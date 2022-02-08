#!/Python/python
import sqlite3


#/*\ ATLANTIS /*\
def checktables():
    table1 = """ CREATE TABLE user (
                uname VARCHAR(255) NOT NULL,
                password CHAR(35) NOT NULL,
                full_name CHAR(35),
                email CHAR(35),
                phone NUMBER NOT NULL,
                sessionid NUMBER NOT NULL,
                PRIMARY KEY (uname)
            ); """

    table2 = """ CREATE TABLE house(
                houseid NUMBER NOT NULL,
                street VARCHAR(35),
                noOfBedrooms NUMBER NOT NULL,
                MonthlyFee NUMBER NOT NULL,
                uname VARCHAR(255) NOT NULL,
                cid NUMBER NOT NULL,
                PRIMARY KEY (houseid),
                CONSTRAINT fk_uname FOREIGN KEY(uname) REFERENCES user(uname),
                CONSTRAINT fk_cid FOREIGN KEY(cid) REFERENCES City(cid)
            ); """

    table3 = """CREATE TABLE City(
                cid NUMBER NOT NULL,
                cname CHAR(35),
                PRIMARY KEY (cid)
            );"""

    conn = sqlite3.connect("users.db")
    c = conn.cursor()
    c.execute(''' SELECT count(name) FROM sqlite_master WHERE type='table' AND name='user' ''')
    if c.fetchone()[0] != 1:
        c.execute(table1)
        conn.commit()
    c.execute(''' SELECT count(name) FROM sqlite_master WHERE type='table' AND name='house' ''')
    if c.fetchone()[0] != 1:
        c.execute(table2)
        conn.commit()
    c.execute(''' SELECT count(name) FROM sqlite_master WHERE type='table' AND name='City' ''')
    if c.fetchone()[0] != 1:
        c.execute(table3)
        conn.commit()
        c.execute(''' INSERT INTO City (cid, cname) VALUES ('1', 'Lefkosa');''')
        conn.commit()
        c.execute(''' INSERT INTO City (cid, cname) VALUES ('2', 'Girne');''')
        conn.commit()
        c.execute(''' INSERT INTO City (cid, cname) VALUES ('3', 'Gazi Magusa');''')
        conn.commit()
        c.execute(''' INSERT INTO City (cid, cname) VALUES ('4', 'Iskele');''')
        conn.commit()
        c.execute(''' INSERT INTO City (cid, cname) VALUES ('5', 'Guzelyurt');''')
        conn.commit()
        c.execute(''' INSERT INTO City (cid, cname) VALUES ('6', 'Lefke');''')
        conn.commit()
    c.close()
