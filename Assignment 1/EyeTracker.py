import copy
import sys
import matplotlib.pyplot as plt

#/*\Atlantis/*\

def bar_graph(value1, value2, gn1, gn2, elementname, pagename, labely):
    groups = [gn1, gn2]
    values = [value1, value2]
    plt.bar(groups, values)
    plt.xlabel('Groups')
    plt.ylabel(labely)
    plt.title("Comparison Between People With & Without Autism\nfor Element " + elementname + " on Page " + pagename)
    plt.show()


dict = {}
UG = {}
EN = {}
LastDict = {}
EmptyTemp = {}
EmptyEN = {}
EmptyUG = {}
sentinel = 1
while sentinel == 1:
    print("Enter the file name:\n")
    x = input()
    if x != "datafile.txt":
        print("Invalid Name.\n")
    else:
        f = open(x)
        sentinel = 3
TimeViewedSum = 0.0
FixationsSum = 0.0
RevisitsSum = 0.0
UserGroup = 'X'
CurrentGroup = 'Y'
CurrentElement = 'X'
ElementName = 'X'
PageName = 'X'
CurrentPage = 'X'
for line in f:
    PageName, ElementName, UserID, UserGender, UserGroup, TimeViewed, Fixations, Revisits = line.split(';')
    if UserGroup != CurrentGroup:  # Resetting the values when iterating next group.
        TimeViewedSum = 0.0
        FixationsSum = 0.0
        RevisitsSum = 0.0
    CurrentGroup = UserGroup
    if ElementName != CurrentElement and CurrentElement != 'X':  # Next Element
        TimeViewedSum = 0.0
        FixationsSum = 0.0
        RevisitsSum = 0.0

        EN.update(EmptyEN)
        EmptyEN = copy.deepcopy(EN)
        EmptyTemp = copy.deepcopy(dict)
        dict.update(EmptyTemp)
        LastDict.update(EmptyTemp)

    if PageName != CurrentPage and CurrentPage != 'X':  # Next PageName
        EmptyTemp = copy.deepcopy(dict)
        LastDict.update(EmptyTemp)
        EmptyEN.clear()
    ####################
    CurrentElement = ElementName
    CurrentPage = PageName
    UG[UserGroup] = {'Time': 0, 'Fixations': 0, 'Revisits': 0}
    EN[ElementName] = UG
    dict[PageName] = EN
    ####
    TimeViewedSum = float(TimeViewed) + TimeViewedSum
    FixationsSum = float(Fixations) + FixationsSum
    RevisitsSum = float(Revisits) + RevisitsSum
    dict[PageName][ElementName][UserGroup]['Time'] = TimeViewedSum
    dict[PageName][ElementName][UserGroup]['Fixations'] = FixationsSum
    dict[PageName][ElementName][UserGroup]['Revisits'] = RevisitsSum

f.close()
sentinel = 1
while sentinel == 1:
    print("\n1.Compare the total time viewed, the total number of fixations or the total number of revisits for")
    print(" people with and without autism for a particular element on a specific web page")
    print("\n2.Compare the total time viewed, the total number of fixations or the total number of revisits for")
    print("people with and without autism on a specific web page")
    print("\n3.Exit")
    option = input()
    if option == '1':
        page = 1
        while page == 1:
            print("Please Enter the Page Name:")
            PageName = input(option)
            if PageName in LastDict.keys():
                print("Please Enter the Element:")
                ElementName = input(option)
                if ElementName in LastDict[PageName].keys():
                    while page == 1:
                        print("Please Enter a Metric: \n (1)-Total Time \n (2)-Fixations \n (3)-Revisits")
                        metric = input()
                        if metric == '1':
                            page = -1
                            bar_graph(LastDict[PageName][ElementName]['ASD']['Time'],
                                      LastDict[PageName][ElementName]['CONTROL']['Time'], "People With Autism",
                                      "People Without Autism", ElementName, PageName, "Total Time Viewed")
                        elif metric == '2':
                            page = -1
                            bar_graph(LastDict[PageName][ElementName]['ASD']['Fixations'],
                                      LastDict[PageName][ElementName]['CONTROL']['Fixations'], "People With Autism",
                                      "People Without Autism", ElementName, PageName, "Total Fixations")
                        elif metric == '3':
                            page = -1
                            bar_graph(LastDict[PageName][ElementName]['ASD']['Revisits'],
                                      LastDict[PageName][ElementName]['CONTROL']['Revisits'], "People With Autism",
                                      "People Without Autism", ElementName, PageName, "Total Revisits")
                        else:
                            print("Please Enter a valid option.")
                else:
                    print("Element Not Found.")
            else:
                print("Page Not Found.")
    elif option == '2':
        TotalRevisitsASD = 0.0
        TotalRevisitsCONTROL = 0.0
        TotalTimeASD = 0.0
        TotalTimeCONTROL = 0.0
        TotalFixationsCONTROL = 0.0
        TotalFixationsASD = 0.0
        page = 2
        while page == 2:
            print("Please Enter the Page Name")
            PageName = input()
            if PageName in LastDict.keys():
                x = (LastDict[PageName].keys())
                for key in LastDict[PageName].keys():
                    TotalTimeASD = LastDict[PageName][key]['ASD']['Time'] + TotalTimeASD
                    TotalTimeCONTROL = LastDict[PageName][key]['CONTROL']['Time'] + TotalTimeCONTROL
                    TotalFixationsASD = LastDict[PageName][key]['ASD']['Fixations'] + TotalFixationsASD
                    TotalFixationsCONTROL = LastDict[PageName][key]['CONTROL']['Fixations'] + TotalFixationsASD
                    TotalRevisitsASD = LastDict[PageName][key]['ASD']['Revisits'] + TotalRevisitsASD
                    TotalRevisitsCONTROL = LastDict[PageName][key]['CONTROL']['Revisits'] + TotalRevisitsCONTROL
                while page == 2:
                    print("Please Enter a Metric: \n (1)-Total Time \n (2)-Fixations \n (3)-Revisits")
                    metric = input()
                    if metric == '1':
                        page = -1
                        bar_graph(TotalTimeASD, TotalTimeCONTROL, "People With Autism",
                                  "People Without Autism", "All Elements", PageName, "Total Time Viewed")
                    elif metric == '2':
                        page = -1
                        bar_graph(TotalFixationsASD, TotalFixationsCONTROL, "People With Autism",
                                  "People Without Autism", "All Elements", PageName, "Total Fixations")
                    elif metric == '3':
                        page = -1
                        bar_graph(TotalRevisitsASD, TotalRevisitsCONTROL, "People With Autism",
                                  "People Without Autism", "All Elements", PageName, "Total Revisits")
                    else:
                        print("Please Enter a valid option.")
            else:
                print("Name not found.")
    elif option == '3':
        print("Exiting...")
        sys.exit()
    else:
        print("Please Enter valid option.")
