#!/python/python

#/*\ ATLANTIS /*\
# New advertisement form page
def printHeader(title):
    print("Content-type: text/html")
    print("")
    print("<html><head><title>{}</title></head><body>".format(title))


def printFooter():
    print("</body></html>")


printHeader("Welcome to the home page!")
print("<html>")
print("<body>")
print("<div class = 'advertise'>")
print("<form name='formAdvertisement' action = 'insert_advertisement.py'"
      "  method='get' id='advform' style='display:block' onsubmit='return validateAdv();'>")
print("<h1>Advertise Form</h1>")
print("<p>Street: <input type='text' name='str' id = 'str' /></p>")
print("<p>City: <input type='text' name='city' id = 'city'/></p>")
print("<p>Number of Bedrooms: <input type='text' name='bedrooms' id = 'bedrooms'/></p>")
print("<p>Monthly Fee: <input type='number' name='fee' id = 'fee'/></p>")
print("<p><input type='submit' value='Submit'>")
print("<input type='reset' value='Reset'></p>")
print("</form>")
print("</div>")
print("</body>")
print("</html>")

printFooter()
