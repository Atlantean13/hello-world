#!/python/python
import sqlite3

#/*\ ATLANTIS /*\
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
cities = {}
conn = sqlite3.connect("users.db")
c = conn.cursor()
c.execute("SELECT * FROM City")
looper1 = (len(c.fetchall()))
c.execute("SELECT cid, cname FROM City")
for index2 in range(0, looper1):
    variables = c.fetchone()
    cities[variables[0]] = variables[1]

c.execute("SELECT * FROM house")
looper2 = (len(c.fetchall()))
c.execute("SELECT street, cid, noOfbedrooms, MonthlyFee FROM house")
##

print(" <input type='text' id='street' onkeyup='search()' placeholder='Filter by street' class='table-search-filters'>")
print(" <input type='text' id='rooms' onkeyup='search()' placeholder='Filter by rooms' class='table-search-filters'>")
print(" <input type='text' id='city' onkeyup='search()' placeholder='Filter by city' class='table-search-filters'>")

##
print("<table id = 'Table'>")
print("<tr>")
print("<th>Street</th>")
print("<th>City</th>")
print("<th>Number Of Bedrooms</th>")
print("<th>Monthly Fee</th>")
print("</tr>")
for index in range(0, looper2):
    variables = c.fetchone()
    print("<tr id = {} > ".format(index))
    print("<td>" + str(variables[0]) + "</td>")
    print("<td>" + cities[variables[1]] + "</td>")
    print("<td>" + str(variables[2]) + "</td>")
    print("<th>" + str(variables[3]) + "</th>")
    # print("<th><p1><button type = 'button' onclick = 'hide({});'>Delete</button></p1></th>".format(index))
    print("</tr>")
print("<tr id='noRecordTR' style='display:none'> <td>No advertisement found</td></tr>")
print("</table>")
print("<a href='index.py'>Click here to return homepage</a>")

printFooter()