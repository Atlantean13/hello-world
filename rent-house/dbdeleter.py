import cgi


#/*\ ATLANTIS /*\
def deleter(idc):
    def printHeader(title):
        print("Content-type: text/html")
        print("")
        print("<html><head><title>{}</title></head><body>".format(title))

    def printFooter():
        print("</body></html>")

    printHeader("deleter")
    print(idc)
    form = cgi.FieldStorage()
    print(form)

    printFooter()
