#!/python/python
# this file takes advertisement values from advertisement_creation_form.py, and inserts them to users.db
import cgi
import http.cookies as Cookie
import sqlite3
import sys
import os

#/*\ ATLANTIS /*\

def printHeader(title):
    print("Content-type: text/html")
    print("")
    print("<html><head><title>{}</title></head><body>".format(title))


def printFooter():
    print("</body></html>")


printHeader("Create")

conn = sqlite3.connect("users.db")
c = conn.cursor()
c.execute("SELECT * FROM house")
conn.commit()
form = cgi.FieldStorage()

if "HTTP_COOKIE" in os.environ:
    cookie = Cookie.SimpleCookie(os.environ["HTTP_COOKIE"])
    if "session" in cookie.keys():
        x = cookie["session"].value
        conn = sqlite3.connect("users.db")
        c = conn.cursor()
        c.execute("SELECT uname FROM user WHERE sessionid = ?", [x])
        user = c.fetchone()
        c.execute("SELECT * FROM house")
        houseid = (len(c.fetchall())) + 1
        c.execute("SELECT cid FROM City WHERE cname = ?", [form["city"].value])
        cid = c.fetchone()
        if cid == None:
            print("City not found in the database!, inserting it.")
            c.execute("SELECT * FROM City")
            cityid = (len(c.fetchall())) + 1
            c.execute("INSERT INTO City VALUES (?, ?)", (str(cityid), str(form["city"].value)))
            conn.commit()
            c.execute(
                " INSERT INTO house VALUES (?, ?, ?, ?, ?, ?)",
                (houseid, str(form["str"].value), int(form["bedrooms"].value), int(form["fee"].value), str(user[0]),
                 int(cityid)))
            print("<a href='index.py'>Advertisement added.Click here to return homepage</a>")
            conn.commit()
        else:
            c.execute(
                " INSERT INTO house VALUES (?, ?, ?, ?, ?, ?)",
                (houseid, str(form["str"].value), int(form["bedrooms"].value), int(form["fee"].value), str(user[0]),
                 int(cid[0])))
            conn.commit()
            print("<a href='index.py'>Advertisement added. Click to return homepage.</a>")
printFooter()
