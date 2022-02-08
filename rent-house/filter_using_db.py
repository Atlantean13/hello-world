#!/python/python

#/*\ ATLANTIS /*\
import cgi
import sqlite3
cities = {}


def printHeader(title):
    print("Content-type: text/html")
    print("")
    print("<html><head><title>{}</title></head><body>".format(title))


def printFooter():
    print("</body></html>")


printHeader("Filter DB")

form = cgi.FieldStorage()
conn = sqlite3.connect("users.db")
c = conn.cursor()
c.execute("SELECT * FROM City")
looper1 = (len(c.fetchall()))
c.execute("SELECT cid, cname FROM City")
for index2 in range(0, looper1):
    variables = c.fetchone()
    cities[variables[0]] = variables[1]
key_list = list(cities.keys())
val_list = list(cities.values())
#
street = None
city = None
bedroom = None
maxN= None
minN = None
tablecount = 0

if "str" not in form.keys():
    street = None
elif(form["str"].value != None):
    street = str(form["str"].value)
if "city" not in form.keys():
    city = None
elif(form["city"].value != None):
    for index in range(0, len(val_list)):
        if val_list[index] == form["city"].value:
            city = key_list[index]
if "bedrooms" not in form.keys():
    bedroom = None
elif(form["bedrooms"].value != None):
    bedroom = int(form["bedrooms"].value)
if "minfee" not in form.keys():
    minN = None
elif(form["minfee"].value != None):
    minN = int(form["minfee"].value)
if "maxfee" not in form.keys():
    maxN = None
elif(form["maxfee"].value != None):
    maxN = int(form["maxfee"].value)

c.execute("SELECT street, cid, noOfbedrooms, MonthlyFee FROM house")
liste = c.fetchall()
length = len(liste)

c.execute("SELECT street, cid, noOfbedrooms, MonthlyFee FROM house")
print("<table id = 'TableDB'>")
print("<tr>")
print("<th>Street Name    |</th>")
print("<th>City Name      |</th>")
print("<th>Bedrooms       |</th>")
print("<th>Monthly Fee    |</th>")
print("</tr>")
for index in range(0, length):
    streetfound = 0
    cityfound = 0
    bedroomfound = 0
    pricefound = 0
    variables = c.fetchone()
    if street != None:
        if (street == variables[0]):
            streetfound = 1
    elif street == None:
        streetfound = 1

    if city != None:
        if(city == variables[1]):
            cityfound = 1
    elif city == None:
        cityfound = 1
    if bedroom != None:
        if(bedroom == variables[2]):
            bedroomfound = 1
    elif bedroom == None:
        bedroomfound = 1
    if (minN != None and maxN != None):
        if minN < variables[3] < maxN:
            pricefound = 1
    elif (minN == None and maxN != None):
        if variables[3] < maxN:
            pricefound = 1
    elif minN != None and maxN == None:
        if variables[3] > minN:
            pricefound = 1
    elif minN == None and maxN == None:
        pricefound = 1
    if streetfound == 1 and cityfound == 1 and bedroomfound == 1 and pricefound == 1:
        print("<tr > ")
        print("<td>" + str(variables[0]) + "</td>")
        print("<td>" + str(cities[variables[1]]) + "</td>")
        print("<td>" + str(variables[2]) + "</td>")
        print("<th>" + str(variables[3]) + "</th>")
        print("</tr>")
        tablecount = tablecount + 1
if tablecount == 0:
    print("<tr > ")
    print("<td>  </td>")
    print("<td> No advertisement </td>")
    print("<td> found. </td>")
    print("</tr>")
print("<tr > ")
print("<td><a href='filter_form.py'>Return to research.</a></td>")
print("</tr>")
printFooter()
