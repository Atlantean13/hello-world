#!/python/python

#/*\ ATLANTIS /*\
# Main File #
# Program Explanation #
# python interpreter location is C:/Python/python.exe
# Used Xampp Control Panel for testing the code.
# path for project --> C:\xampp\htdocs\rent-house
# We used .py for homepage and .html for login and register pages.
# We divided program to multiple function files for readability and they are explained below.

# RegistrationForm folder contains register page and its .css file. After clicking register button, process.py will
# insert user to database. then you will return to main.py

# LoginForm Folder contains login page and its .css file. After clicking login button, login.py will handle cookie and
# user information and then returns to main.py

# tablecreator.py is used to control the tables. if tables are missing in users.db, this script will create empty tables

# logout.py handles logout process and returns back to main.py

# advertisement_creation_form.py is called when user clicks create advertisement button on the homepage. It displays
# the advertisement creation page and then submits the form to insert.advertisement.py

# insert.advertisement.py gets the values using cgi, and inserts them to database.

# print_logged_user_ads.py is called when user clicks list my advertisements button on the homepage. It will display the
# ads created by current user.

# dbdeleter.py is not implemented. Intend was to use it for deleting the advertisements when delete button is clicked.

# filterer.py is called when user clicks javascript test filter button, not wanted in assignment, just an addition.

# filter_form.py is called when user clicks filter using database button on the homepage. It displays the filter form
# and sends the values to filter_using_db.py

# filter_using_db.py gets all ads from database, and filters it by the given criterias.


import http.cookies as Cookie
import sqlite3
import os
from tablecreator import checktables

cities = {}
checktables()


def printHeader():
    print("Content-type: text/html")
    print("")


def printFooter():
    print("</body></html>")


printHeader()
print("<head>")
print("<title>House Rental Cyprus</title>")
print("<script ")
print("src = 'jscript.js'>")
print("</script>")
print("<link href = 'LoginForm/index.html' rel = 'import' />"
      "<link href = 'RegistrationForm/index.html' rel = 'import' />"
      "<link href = 'AfterLogin/index.html' rel = 'import' />"
      "<link href = 'css/style.css' rel = 'stylesheet' type = 'text/css' media = 'all'  />")
print("</head><body>")
print("<div class='container'>"
      "<p2><p id='p1'>Welcome to the Main Page of House Rental Cyprus</p>"
      "<br/><br/>")
if "HTTP_COOKIE" not in os.environ:  # if not logged in, show login and register buttons.
    print("<button id = 'myButton' button type ='button' "
          "onclick=\"location.href = 'http://localhost/rent-house/RegistrationForm/index.html';\">"
          "Register</button>"
          "<br/><br/>"
          "<button type='button' onclick=\"location.href = 'http://localhost/rent-house/LoginForm/index.html';\">"
          "Login</button>")
print("<br/><br/>")
conn = sqlite3.connect("users.db")
c = conn.cursor()
c.execute("SELECT * FROM City")
looper1 = (len(c.fetchall()))  # City count
c.execute("SELECT cid, cname FROM City")
for index2 in range(0, looper1):  # Storing city names and city ids in dictionary for easy table creation.
    variables = c.fetchone()
    cities[variables[0]] = variables[1]
c.execute("SELECT * FROM house")  # advertisement count
looper2 = (len(c.fetchall()))
c.execute(
    "SELECT street, cid, noOfbedrooms, MonthlyFee FROM "
    "(SELECT * FROM house ORDER BY houseid DESC LIMIT 10) ORDER BY houseid DESC;")
# table creation
print("<table id = 'table1'>")
print("<caption>Last 10 Advertisements</caption>")
print("<thead>")
print("<tr>")
print("<th scope=\"col\">Street</th>")
print("<th scope=\"row\">City</th>")
print("<th scope=\"row\">Number Of Bedrooms</th>")
print("<th scope=\"row\">Monthly Fee</th>")
print("</tr>")
print("</thead><tbody>")
for index in range(0, looper2):
    variables = c.fetchone()
    if variables != None:  # loop for creating rows per advertisement.
        print("<tr id = {} > ".format(index))
        print("<th scope=\"row\">" + str(variables[0]) + "</th>")
        print("<td>" + cities[variables[1]] + "</td>")
        print("<td>" + str(variables[2]) + "</td>")
        print("<td>" + str(variables[3]) + "</td>")
        print("</tr>")
print("</tbody>")
print("</table>")
if "HTTP_COOKIE" in os.environ:  # if logged in
    cookie = Cookie.SimpleCookie(os.environ["HTTP_COOKIE"])
    if "session" in cookie.keys():
        x = cookie["session"].value
        c.execute("SELECT * FROM user WHERE sessionid = ?", (cookie["session"].value,))
        row = c.fetchone()
        if row != None:  # logged user functions here, create advertisement, list my advertisements, filter
            print("<p>Welcome {}!</p>".format(row[0]))
            print("<p1><button type = 'button' onclick = 'printten();'>List my advertisements</button></p1>")
            print("<br></br>")
            print("<p2><button type = 'button' onclick = 'gotolist();'>Create new advertisement</button></p2>")
            print("<br></br>")
            print(
                "<p3><button type = 'button' onclick = 'filter();'>Filter Ads Interactively(javascript,for testing)</button></p3>")
            print("<p4><button type = 'button' onclick = 'filterfromdb();'>Filter from Database</button></p4>")
            print("<br></br>")
            print("<a href='logout.py'>Click here to logout</a>")
        else:
            print("<p>You are not Logged in!")
        conn.close()
    else:
        print("<p>You are not Logged in!!")
else:
    print(
        "<p3><button type = 'button' onclick = 'filter();'>Filter Ads Interactively(javascript,for testing)</button></p3>")
    print("<p4><button type = 'button' onclick = 'filterfromdb();'>Filter from Database</button></p4>")
    print("<p>You are not Logged in!")
print(" </p2></div>")
printFooter()
