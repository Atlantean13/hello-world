#!/python/python

#/*\ ATLANTIS /*\
# file for printing logged user's advertisements.
import http.cookies as cookie
import sqlite3
import os

cities = {}


def printHeader(title):
    print("Content-type: text/html")
    print("")
    print("<html><head><title>{}</title></head><body>".format(title))


def printFooter():
    print("</body></html>")


printHeader("printer")
print("<script ")
print("src = 'jscript.js'>")
print("</script>")
print("<script>")
print("function mm() {")
print("location.replace('index.py');}")
print("</script>")
if "HTTP_COOKIE" in os.environ:
    cookie = cookie.SimpleCookie(os.environ["HTTP_COOKIE"])
    if "session" in cookie.keys():

        x = cookie["session"].value
        conn = sqlite3.connect("users.db")
        c = conn.cursor()
        c.execute("SELECT * FROM City")
        looper1 = (len(c.fetchall()))
        c.execute("SELECT cid, cname FROM City")
        for index2 in range(0, looper1):
            variables = c.fetchone()
            cities[variables[0]] = variables[1]
        c.execute("SELECT uname FROM user WHERE sessionid = ?", [x])
        user = c.fetchone()
        c.execute("SELECT * FROM house")
        looper2 = (len(c.fetchall()))
        c.execute("SELECT street, cid, noOfbedrooms, MonthlyFee FROM house WHERE uname = ?", user)
        print("<p1><button type = 'button' onclick = 'mm();'>Return to homepage</button></p1>")
        print("<br></br>")
        print("<table>")
        print("<tr>")
        print("<th>Street</th>")
        print("<th>City</th>")
        print("<th>Number Of Bedrooms</th>")
        print("<th>Monthly Fee</th>")
        print("<th>Delete</th>")
        print("</tr>")
        for index in range(0, looper2):
            variables = c.fetchone()
            print("<tr id = {} > ".format(index))
            print("<td>" + str(variables[0]) + "</td>")
            print("<td>" + cities[variables[1]] + "</td>")
            print("<td>" + str(variables[2]) + "</td>")
            print("<th>" + str(variables[3]) + "</th>")
            print("<th><p1><button type = 'button' onclick = 'hide({});'>Delete</button></p1></th>".format(index))
            print("</tr>")
        print("</table>")

printFooter()
