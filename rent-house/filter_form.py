#!/python/python

#/*\ ATLANTIS /*\
# New advertisement form page
def printHeader(title):
    print("Content-type: text/html")
    print("")
    print("<html><head><title>{}</title></head><body>".format(title))


def printFooter():
    print("</body></html>")


printHeader("Filter page")
print("<html>")
print("<body>")
print("<div class = 'advertise'>")
print("<form name='filter' action = 'filter_using_db.py'"
      "  method='get' id='advform' style='display:block' >")
print("<h1>Filter</h1>")
print("<p>Street: <input type='text' name='str' id = 'str' /></p>")
print("<p>City: <input type='text' name='city' id = 'city'/></p>")
print("<p>Number of Bedrooms: <input type='number' name='bedrooms' id = 'bedrooms'/></p>")
print("<p>Min monthly Fee: <input type='number' name='minfee' id = 'minfee'/></p>")
print("<p>Max monthly Fee: <input type='number' name='maxfee' id = 'maxfee'/></p>")
print("<p><input type='submit' value='Submit'>")
print("<input type='reset' value='Reset'></p>")
print("</form>")
print("<a href='index.py'>Click here to return homepage</a>")
print("</div>")
print("</body>")
print("</html>")

printFooter()
