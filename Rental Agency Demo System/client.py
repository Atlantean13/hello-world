import socket
from tkinter import *
from tkinter import messagebox

#/*\Atlantis/*\

class LoginScreen(Frame):
    def __init__(self):
        Frame.__init__(self)
        self.pack()
        self.master.title("Login")

        self.frame1 = Frame(self)
        self.frame1.pack(padx=10, pady=10)

        self.userNameLabel = Label(self.frame1, text="User name")
        self.userNameLabel.pack(side=LEFT, padx=10, pady=10)

        self.userName = Entry(self.frame1, name="username")
        self.userName.pack(side=LEFT, padx=10, pady=10)

        self.frame2 = Frame(self)
        self.frame2.pack(padx=10, pady=10)

        self.passwordLabel = Label(self.frame2, text="Password")
        self.passwordLabel.pack(side=LEFT, padx=10, pady=10)

        self.password = Entry(self.frame2, name="password", show="*")
        self.password.pack(side=LEFT, padx=10, pady=10)

        self.frame3 = Frame(self)
        self.frame3.pack(padx=10, pady=10)

        self.login = Button(self.frame3, text="Login", command=self.buttonPressed)
        self.login.pack(side=LEFT, padx=10, pady=10)
        # self.login.config(Background="red")

    def buttonPressed(self):
        username = self.userName.get()
        password = self.password.get()
        message = ("login;"+username+";"+password).encode()
        mySocket.send(message)
        message = mySocket.recv(1024).decode()
        if message == "loginfailure":
            messagebox.showinfo("Message", "Invalid Credentials!")
        else:
            code, username, role = message.split(";")
            role = role.rstrip("\n")
            if role == "employee":
                window.quit()
                window.destroy()
                window2 = Employee()
                window2.mainloop()
            else:
                window.quit()
                window.destroy()
                window3 = Manager()
                window3.mainloop()


class Employee(Frame):
    # Frames
    def __init__(self):
        Frame.__init__(self)
        self.pack()
        self.master.title("Employee")

        self.frame1 = Frame(self)
        self.frame1.pack(padx=10, pady=10)

        self.ApartmentCodeLabel = Label(self.frame1, text="Apartment Code")
        self.ApartmentCodeLabel.pack(side=LEFT, padx=10, pady=10)

        self.aptCode = Entry(self.frame1, name="aptCode")
        self.aptCode.pack(side=LEFT, padx=10, pady=10)

        self.frame2 = Frame(self)
        self.frame2.pack(padx=10, pady=10)

        self.startDateLabel = Label(self.frame2, text="Start Date")
        self.startDateLabel.pack(side=LEFT, padx=10, pady=10)

        self.startDate = Entry(self.frame2, name="startDate")
        self.startDate.pack(side=LEFT, padx=10, pady=10)

        self.frame3 = Frame(self)
        self.frame3.pack(padx=10, pady=10)

        self.endDateLabel = Label(self.frame3, text="End Date")
        self.endDateLabel.pack(side=LEFT, padx=10, pady=10)

        self.endDate = Entry(self.frame3, name="endDate")
        self.endDate.pack(side=LEFT, padx=10, pady=10)

        self.frame4 = Frame(self)
        self.frame4.pack(padx=10, pady=10)

        self.cNameLabel = Label(self.frame4, text="Customer Name")
        self.cNameLabel.pack(side=LEFT, padx=10, pady=10)

        self.cName = Entry(self.frame4, name="cName")
        self.cName.pack(side=LEFT, padx=10, pady=10)

        self.frame5 = Frame(self)
        self.frame5.pack(padx=10, pady=10)

        self.login = Button(self.frame5, text="Show", command=self.buttonS)
        self.login.pack(side=LEFT, padx=10, pady=10)

        self.frame6 = Frame(self)
        self.frame6.pack(padx=10, pady=10)

        self.login = Button(self.frame6, text="Reserve", command=self.buttonR)
        self.login.pack(side=RIGHT, padx=10, pady=10)
    # Frames End

    def buttonS(self):  # Show Apartment Part
        apartmentcode = self.aptCode.get()
        startdate = self.startDate.get()
        enddate = self.endDate.get()
        message = ("apartment;"+apartmentcode+";"+startdate+";"+enddate).encode()
        mySocket.send(message)
        message = mySocket.recv(1024).decode()
        if message == "invalidapartmentcode":
            messagebox.showerror("Error", "Apartment not found")
        else:
            opcode, apartmentcode, address, city, postcode, size, bedrooms, available = message.split(";")
            messagebox.showinfo("Apartment Info", "Apartmentcode: "+apartmentcode+"\nCity: "+city+"\nPostcode: "+postcode
                                + "\nSize: "+size+"\nBedrooms: "+bedrooms+"\nAvailable: "+available)

    def buttonR(self):  # Make Reservation Part
        apartmentcode = self.aptCode.get()
        startdate = self.startDate.get()
        enddate = self.endDate.get()
        customername = self.cName.get()
        message = ("reservation;"+apartmentcode+";"+startdate+";"+enddate+";"+customername).encode()
        mySocket.send(message)
        message = mySocket.recv(1024).decode()
        if message == "invalidapartmentcode":
            messagebox.showerror("Error", "Invalid Apartment Code")
        elif message == "notavailable":
            messagebox.showerror("Error", "Apartment Unavailable")
        else:
            messagebox.showinfo("Info", "Reservation successful")


class Manager(Frame):
    # Frame
    def __init__(self):
        Frame.__init__(self)
        self.pack()
        self.master.title("Manager")
        self.frame1 = Frame(self)
        self.frame1.pack()

        self.Label1 = Label(self.frame1, text="Select your Report:", width=60, font="Arial 10")
        self.Label1.pack(padx=5, pady=5)

        self.frame2 = Frame(self)
        self.frame2.pack()
        self.svar = StringVar(self.frame2, "1")

        reportselections = {"(1) Which employee makes the highest number of reservations?": "1",
                            "(2) Which apartment is the most popular?": "2",
                            "(3) How many apartments are currently available?": "3",
                            "(4) How many apartments have not been reserved yet?": "4"}
        for(text, report) in reportselections.items():
            Radiobutton(self.frame2, text=text, variable=self.svar, value=report,).pack(side=TOP, ipady=5)
        self.frame3 = Frame(self)
        self.frame3.pack(padx=10, pady=10)
        self.request = Button(self.frame3, text="Request", command=self.getreport)
        self.request.pack(side=LEFT, padx=10, pady=10)

        self.frame4 = Frame(self)
        self.frame3.pack(padx=10, pady=10)
        self.exit = Button(self.frame3, text="Exit", command=self.disconnect)
        self.exit.pack(side=RIGHT, padx=10, pady=10)
    # Frame

    def getreport(self):    # Report Handling
        message = ("report"+self.svar.get()).encode()
        mySocket.send(message)
        message = mySocket.recv(1024).decode()
        messagedec = message+";"
        report, others = messagedec.split(";", 1)
        if report == "report1":
            reportname, employee = message.split(";")
            messagebox.showinfo("Report1", employee+" makes the highest number of reservations.")
        elif report == "report2":
            reportname, apartment = message.split(";")
            messagebox.showinfo("Report2", apartment+" is the most populer apartment.")
        elif report == "report3":
            reportname, others = message.split(";", 1)
            if not others:
                messagebox.showinfo("Report3", "All apartments are reserved.")
            else:
                messagebox.showinfo("Report3", "Available apartments: " + (others.replace(";", " ")))
        else:
            reportname, others = message.split(";", 1)
            messagebox.showinfo("Report4", (others.replace(";", " "))+"not reserved.")

    def disconnect(self):   # Terminate Connection
        message = "exit".encode()
        mySocket.send(message)
        mySocket.close()
        Frame.quit(self)
        Frame.destroy(self)
        exit(1)

# Creating Socket


HOST = "127.0.0.1"
PORT = 5000
mySocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
try:
    mySocket.connect((HOST, PORT))
except socket.error:
    print("Connection failed.")
    exit(1)
serverMessage = mySocket.recv(1024).decode()
# login part
if serverMessage == "connectionsuccess":  # Start with Login Screen
    window = LoginScreen()
    window.mainloop()
mySocket.close()
