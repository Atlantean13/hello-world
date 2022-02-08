#!/python/python

#/*\ ATLANTIS /*\
import http.cookies as Cookie
import random
import sqlite3
import os

def printHeader(title):
    print ("Content-type: text/html")
    print ("")
    print ("<html><head><title>{}</title></head><body>".format(title))

def printFooter():
    print ("</body></html>")


printHeader("Logout process")

if "HTTP_COOKIE" in os.environ:
    cookie = Cookie.SimpleCookie(os.environ["HTTP_COOKIE"])
    if "session" in cookie.keys():
        conn = sqlite3.connect("users.db")
        c = conn.cursor()
        c.execute("SELECT * FROM USER WHERE sessionid= ?", (cookie["session"].value,))
        row = c.fetchone()
        if row != None:
            c.execute("UPDATE USER SET sessionid = -1 WHERE uname = ?", (row[0],))
            conn.commit()
            print ("<script>")
            print ("document.cookie = 'session=; expires=Thu, 01 Jan 1970 00:00:00 UTF; path=/;';")
            print ("</script>")
            print ("<p>Logout is successful</p>")
            print("<script>")
            print("window.location = 'index.py';")
            print("</script>")
        else:
            print ("<p>No matching user!</p>")
            print("<script>")
            print("window.location = 'index.py';")
            print("</script>")
        conn.close()
    else:
        print ("<p>Login required!</p>")
        print("<script>")
        print("window.location = 'index.py';")
        print("</script>")
else:
    print ("<p>Login required!</p>")
    print("<script>")
    print("window.location = 'index.py';")
    print("</script>")

printFooter()