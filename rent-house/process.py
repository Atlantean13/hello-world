#!/Python/python
import cgi
import sqlite3

#/*\ ATLANTIS /*\

def printHeader(title):
    print("Content-type: text/html")
    print("")
    print("<html><head><title>{}</title></head><body>".format(title))


def printFooter():
    print("</body></html>")


def countDigits(value):
    counter = 0
    for p in value:
        if p.isdigit():
            counter += 1
    return counter


printHeader("Processing")

form = cgi.FieldStorage()

if "uname" not in form.keys():
    print("<p>Username should be entered!</p>")
elif "pwd" not in form.keys():
    print("<p>Password should be entered!</p>")
elif "pwd2" not in form.keys():
    print("<p>Password should be re-entered</p>")
elif "fullname" not in form.keys():
    print("<p>Full name should be entered</p>")
elif form["pwd"].value != form["pwd2"].value:
    print("<p>Passwords should be the same!</p>")
elif len(form["pwd"].value) < 5:
    print("<p>Password should include at least 5 chars</p>")
elif countDigits(form["pwd"].value) < 2:
    print("<p>Password should include at least 2 digits</p>")
else:
    conn = sqlite3.connect("users.db")
    c = conn.cursor()
    conn.execute("SELECT * FROM USER WHERE uname = ?", (form["uname"].value,))
    row = c.fetchone()
    if row != None:
        print("<p>User is already in the database</p>")
        print("\n<p>Returning to the registration site in 3 seconds...</p>")
        print("<meta http-equiv='refresh' content = '3 URL=http://localhost/rent-house/RegistrationForm/index.html' />")

    else:
        c.execute("INSERT INTO USER VALUES (?, ?, ?, ?, ?, ?)", (
            form["uname"].value, form["pwd"].value, form["fullname"].value, form["e-mail"].value, form["number"].value,
            -1))
        print("<p>User is added into the database</p>")
        print("<a href='index.py'>Click here to return homepage</a>")
        conn.commit()
    conn.close()

printFooter()
