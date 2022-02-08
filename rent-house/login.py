#!/python/python

#/*\ ATLANTIS /*\
# login file
import http.cookies as Cookie
import random
import sqlite3
import cgi


def printHeader(title):
    print("Content-type: text/html")
    print("")
    print("<html><head><title>{}</title></head><body>".format(title))


def printFooter():
    print("</body></html>")


printHeader("Login")

form = cgi.FieldStorage()
if "Uname" in form.keys() and "Pass" in form.keys():
    conn = sqlite3.connect("users.db")
    c = conn.cursor()
    c.execute("SELECT * FROM USER WHERE uname = ? AND password = ?", (form["Uname"].value, form["Pass"].value))
    row = c.fetchone()
    if row != None:
        print("<p>Login successful</p>")
        cookie = Cookie.SimpleCookie()
        cookie["session"] = random.randint(1, 1000000)
        cookie["session"]["domain"] = "localhost"
        cookie["session"]["path"] = "/"
        c.execute("UPDATE USER SET sessionid = ? WHERE uname = ?", (cookie["session"].value, form["Uname"].value))
        conn.commit()
        print("<script>")
        print("document.cookie = '{}';".format(cookie.output().replace("Set-Cookie: ", "")))  # Seting cookie with JS
        print("window.location = 'index.py';")
        print("</script>")
    else:
        print("<p>Incorrect username or password</p>")
    conn.close()
else:
    print("<p>Please enter your username and password</p>")

printFooter()
