from datetime import date
import socket
#
#/*\Atlantis/*\
# Calculating the amount of days the user wants to reserve,
# and then comparing with the start dates in the reservation.txt file


def timecalculator(apartmentcodeT, startdateT, enddateT):
    months = {"01": 31, "02": 28, "03": 31, "04": 30, "05": 31, "06": 30, "07": 31, "08": 31, "09": 30, "10": 31,
              "11": 30, "12": 31}

    stDay, stMonth, stYear = startdateT.split("/")
    enDay, enMonth, enYear = enddateT.split("/")
    diffM = int(enMonth) - int(stMonth)
    diffY = int(enYear) - int(stYear)
    newDiff = 0

    if diffY <= 1:
        newDiff = (int(months.get(stMonth))) - (int(stDay))
        if diffM == 0:
            newDiff = newDiff - (int(months.get(stMonth)) - (int(enDay)))
        while diffM < 0:
            stMonth = int(stMonth)+1
            stMonth = int(stMonth) % 12
            newDiff = newDiff + (int(months.get(stMonth)))
            if stMonth == enMonth:
                newDiff = newDiff - (int(months.get(stMonth)) - (int(enDay)))
            diffM = (abs(diffM) + 1) % 12

        while diffM > 0:
            stMonth = int(stMonth)+1
            stMonth = int(stMonth) % 12
            newDiff = newDiff + (int(months.get(stMonth)))
            if stMonth == enMonth:
                newDiff = newDiff - (int(months.get(stMonth)) - (int(enDay)))
            diffM = (abs(diffM) - 1) % 12

    elif diffY > 1:
        newDiff = 365 * diffY
        newDiff = newDiff + (int(months.get(stMonth)) - int(stDay))
        if diffM == 0:
            newDiff = newDiff - (int(months.get(stMonth)) - (int(enDay)))
        while diffM < 0:
            stMonth = int(stMonth)+1
            stMonth = int(stMonth) % 12
            newDiff = newDiff + int(months.get(stMonth))
            if stMonth == enMonth:
                newDiff = newDiff - (months.get(stMonth) - int(enDay))
            diffM = (abs(diffM) + 1) % 12

        while diffM > 0:
            stMonth = int(stMonth) + 1
            stMonth = int(stMonth) % 12
            newDiff = newDiff + int(months.get(stMonth))
            if stMonth == enMonth:
                newDiff = newDiff - int((months.get(stMonth)) - int(enDay))
            diffM = (abs(diffM) - 1) % 12

    day, month, year = startdateT.split("/")
    totalDays = newDiff
    datecalculation = startdateT
    print(type(totalDays))
    file = open("reservations.txt")
    temp = totalDays
    for linesf in file.readlines():
        totalDays = temp
        aptCode, name, dateS, dateE, role = linesf.split(";")
        if aptCode == apartmentcodeT:
            while totalDays > 0:
                if dateS == str(datecalculation):
                    print("THE DATES YOU ENTERED ARE ALREADY RESERVED")
                    file.close()
                    return 0
                if int(day) % months.get(month) == 0:
                    month += 1
                    day = 1
                    totalDays -= 1
                elif int(day) % months.get(month) != 0:
                    day = int(day) + 1
                    totalDays -= 1
                elif int(day) == 31 and int(month) == 12:
                    year += 1
                    month = 1
                    day = 1
                    totalDays -= 1
                datecalculation = str(day) + "/" + str(month) + "/" + str(year)
    file.close()
    return 1

# Server Creation


if __name__ == "__main__":
    HOST = "127.0.0.1"
    PORT = 5000
    counter = 0
    mySocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        mySocket.bind((HOST, PORT))
    except socket.error:
        print("Failed to bind")
    while 1:
        print("Waiting for connection...")
        mySocket.listen()
        connection, address = mySocket.accept()
        print("Connection is received from ", address[0])
        msg = "connectionsuccess".encode()
        connection.send(msg)
        currentUser = "None"        # Used for writing inside the reservations table
        clientMsg = connection.recv(1024).decode()
        while clientMsg != "exit":
            success = 0
            operation = clientMsg+";"
            opcode, others = operation.split(";", 1)  # seperating the operation from the message for looping
            if opcode == "login":   # Login Part
                operation, input1, input2 = clientMsg.split(";")
                z = open("users.txt")
                for lines in z.readlines():
                    userName, pw, role2 = lines.split(";")
                    if (userName == input1) and (pw == input2):
                        msg = ("loginsuccess;"+userName+";"+role2).encode()
                        success = 1
                        currentUser = userName
                        z.close()
                        connection.send(msg)
                        break
                if success == 0:
                    msg = "loginfailure".encode()
                    connection.send(msg)
                z.close()
            elif opcode == "apartment":     # Show Apartment Part
                found = 0
                operation, apartmentcodeS, startdateS, enddateS = clientMsg.split(";")
                r = open("reservations.txt")
                for lines in r.readlines():
                    apartmentcodeR, customername, startdateR, enddateR, employee = lines.split(";")
                    if apartmentcodeS == apartmentcodeR:  # check the start date
                        p = open("apartments.txt")
                        for linesA in p.readlines():
                            apartmentcode, address, city, postcode, size, bedrooms = linesA.split(";")
                            if apartmentcode == apartmentcodeS:
                                msg = ("apartment;"+apartmentcode+";"+address+";"+city+";"+postcode+";"+size+";"
                                       + bedrooms+";"+'1').encode()
                                # availability is not implemented, so its just shows the apartment.
                                connection.send(msg)
                                found = 1
                                break
                        p.close()
                r.close()
                if found == 0:
                    msg = "invalidapartmentcode".encode()
                    connection.send(msg)

            elif opcode == "exit":      # Terminating
                print("Terminating")

            elif opcode == "reservation":   # Reservation Part
                check = 0
                opcode, apartmentcode, startdate, enddate, empname = clientMsg.split(";")
                q = open("apartments.txt")
                for line in q.readlines():
                    apartmentcodeA, address, city, postcode, size, bedrooms = line.split(";")
                    if apartmentcodeA == apartmentcode:
                        check = 1
                        break
                if check == 0:
                    message = "invalidapartmentcode".encode()
                    connection.send(message)
                else:   # Report Part
                    result = timecalculator(apartmentcode, startdate, enddate)  # Checks the given dates
                    if result == 1:  # add it to file
                        f = open("reservations.txt", "a")
                        f.write("\n")
                        f.write(apartmentcode+";"+empname+";"+startdate+";"+enddate+";"+currentUser)
                        f.close()
                        message = "successfulreservation".encode()
                        connection.send(message)
                    else:
                        message = "notavailable".encode()
                        connection.send(message)
            else:   # report
                if opcode == "report1":
                    # report1 -- Creates a list from the most repeated employees from the
                    # reservations.txt file, then sends the list to client
                    lst = []
                    f = open("reservations.txt")
                    for lines in f.readlines():
                        apartmentcodeR, customername, startdateR, enddateR, employee = lines.split(";")
                        employee = employee.rstrip("\n")
                        lst.append(employee)

                    lastlist = []
                    sent = 1
                    count2 = 0
                    item = (max(set(lst), key=lst.count))
                    count = lst.count(item)
                    lastlist.append(item)
                    for i in range(0, count):
                        lst.remove(item)
                    while sent == 1:
                        if not lst:
                            sent = 0
                        else:
                            item = (max(set(lst), key=lst.count))
                            count2 = lst.count(item)
                            if count == count2:
                                lastlist.append(item)
                            for i in range(0, count2):
                                lst.remove(item)
                    message = ("report1;"+str(lastlist)).encode()
                    f.close()
                    connection.send(message)
                elif opcode == "report2":
                    # report2 -- Creates a list from the most repeated apartments from the
                    # reservations.txt file, then sends the list to client
                    lst = []
                    f = open("reservations.txt")
                    for lines in f.readlines():
                        apartmentcodeR, customername, startdateR, enddateR, employee = lines.split(";")
                        lst.append(apartmentcodeR)
                    lastlist = []
                    sent = 1
                    count2 = 0
                    item = (max(set(lst), key=lst.count))
                    count = lst.count(item)
                    lastlist.append(item)
                    for i in range(0, count):
                        lst.remove(item)
                    while sent == 1:
                        if not lst:
                            sent = 0
                        else:
                            item = (max(set(lst), key=lst.count))
                            count2 = lst.count(item)
                            if count == count2:
                                lastlist.append(item)
                            for i in range(0, count2):
                                lst.remove(item)
                    message = ("report2;"+str(lastlist)).encode()
                    f.close()
                    connection.send(message)
                elif opcode == "report3":
                    # Compares today's time with the dates inside the reservations.txt file. Checks if the apartment is
                    # free today, and sends free apartments to client.
                    today = date.today()
                    lst = ""
                    blacklist = []
                    whitelist = []
                    d1 = today.strftime("%d/%m/%Y")
                    tday, tmonth, tyear = d1.split("/")
                    tday = int(tday)
                    tmonth = int(tmonth)
                    tyear = int(tyear)
                    n = open("apartments.txt")
                    m = open("reservations.txt")
                    for line in m.readlines():
                        check = 0
                        apartmentcodeR, customername, startdateR, enddateR, employee = line.split(";")
                        print("apartmentcodeR = ", apartmentcodeR)
                        startd, startm, starty = startdateR.split("/")
                        startd = int(startd)
                        startm = int(startm)
                        starty = int(starty)
                        endd, endm, endy = enddateR.split("/")
                        endd = int(endd)
                        endm = int(endm)
                        endy = int(endy)
                        if tyear == starty and tyear == endy:
                            if tmonth > startm and tmonth > endm:
                                check = 1
                            elif tmonth < startm or tmonth < endm:
                                check = 0
                                blacklist.append(apartmentcodeR)
                            elif tmonth == startm and tmonth == endm:
                                if startd < tday < endd:
                                    check = 0
                                    blacklist.append(apartmentcodeR)
                                else:
                                    check = 1
                        elif tyear < endy:
                            check = 0
                            blacklist.append(apartmentcodeR)
                        else:
                            check = 0
                            blacklist.append(apartmentcodeR)
                        if check == 1:
                            if apartmentcodeR in blacklist or apartmentcodeR in whitelist:
                                lst = lst
                            else:
                                lst = lst+apartmentcodeR+";"
                                whitelist.append(apartmentcodeR)
                    n.close()
                    m.close()
                    n = open("apartments.txt")
                    for line3 in n.readlines():
                        apartmentcodeA, address, city, postcode, size, bedrooms = line3.split(";")
                        if apartmentcodeA not in blacklist and apartmentcodeA not in whitelist:
                            lst = lst + apartmentcodeA + ";"
                            whitelist.append(apartmentcodeA)
                    n.close()
                    print(lst)
                    message = ("report3;"+lst).encode()
                    connection.send(message)
                else:
                    # Checks the files and sends the free apartments to client.
                    emptyApt = ""
                    f = open("apartments.txt")
                    p = open("reservations.txt")
                    for lines in f.readlines():
                        apartmentcodeA, address, city, postcode, size, bedrooms = lines.split(";")
                        reserved = 0
                        for lines2 in p.readlines():
                            apartmentcodeR, customername, startdateR, enddateR, employee = lines2.split(";")
                            if apartmentcodeA == apartmentcodeR:
                                reserved = 1
                                break
                        p.seek(0)
                        if reserved == 0:
                            emptyApt = emptyApt+apartmentcodeA+";"
                    p.close()
                    f.close()
                    message = ("report4;"+emptyApt).encode()
                    connection.send(message)
            clientMsg = connection.recv(1024).decode()

        print("Connection terminated.")
        connection.close()
