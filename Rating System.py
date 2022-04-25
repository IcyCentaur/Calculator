import os

import mysql.connector
db = mysql.connector.connect(host = "localhost",user = "root",passwd = "darsh")
c = db.cursor(buffered=True)
c.execute("create database if not exists rating;")
c.execute("use rating;")
c.execute("create table if not exists data(NAME varchar(20) , Story decimal(3), Characters decimal(3), Visuals decimal(3), Audio decimal(3), Enjoyment decimal(3));")


def int_input(val):
    try:
        data = int(input("Enter {}".format(val)))
        return data
    except:
        print("\nPlease enter an integer.\n")
        return int_input(val)


def check_user():
    
    print("THIS APPLICATION IS USED TO RATE ANIME.\n")

    user = input("Enter your name :")

    c.execute("select * from data where NAME = '{}'".format(user))
    d = c.fetchall()
    if d != []:
        
        st,ch,vi,au,en = d[0][1],d[0][2],d[0][3],d[0][4],d[0][5]
        
        print("You have provided how important an aspect is as :")
        print("""\nPlot : {}
Characters : {}
Visuals : {}
Audio : {}
Enjoyment : {}""".format(st,ch,vi,au,en))

        while True:
            
            qy = input("\nWould you like to continue? :") 
            print()

            if qy.lower() == 'yes':
                os.system('cls')
                break
            elif qy.lower() == 'no':

                print("""Would you like to :
1. Delete the data.
2. Modify the data.
3. Change user.
4. Continue without change.\n""")

                x = 1

                while x == 1:

                    qy2 = input("Insert option number :")

                    if qy2 == '1':
                        c.execute("delete from data where NAME = '{}'".format(user))
                        print("Your Data has been deleted succesfully.")
                        print("(Press Enter)")
                        input()
                        os.system('cls')
                        return check_user()

                    elif qy2 == '2':
                        os.system("cls")
                        c.execute("delete from data where NAME = '{}'".format(user))
                        print("Please enter the new values below.\n")
                        st = int_input("the importance of the plot out of 100 (Previously {}) :".format(d[0][1]))
                        ch = int_input("the importance of characters out of 100 (Previously {}) :".format(d[0][2]))
                        vi = int_input("the importance of visuals out of 100 (Previously {}) :".format(d[0][3]))
                        au = int_input("the importance of audio out of 100 (Previously {}) :".format(d[0][4]))
                        en = int_input("the importance of enjoyment out of 100 (Previously {}) :".format(d[0][5]))
                        c.execute("insert into data values('{}',{},{},{},{},{})".format(user,st,ch,vi,au,en))
                        os.system("cls")
                        x = 0

                    elif qy2 == '3':
                        os.system("cls")
                        return check_user()

                    elif qy2 == '4':
                        print("Press Enter to continue.")
                        input()
                        os.system('cls')
                        x = 0

                    else:
                        print("\nPlease enter valid option number.\n")
                break

            else:
                print('Please answer in yes or no.')

    else:
        print('\nA new account in the name of "{}" shall be created...'.format(user))
        print("Press 1 to change user or press enter to continue.\n")
        qy = input()
        if qy == '1':
            os.system("cls")
            return check_user()
        else:
            pass
        st = int_input("the importance of the plot out of 100 : ")
        ch = int_input("the importance of characters out of 100 : ")
        vi = int_input("the importance of visuals out of 100 : ")
        au = int_input("the importance of audio out of 100 : ")
        en = int_input("the importance of enjoyment out of 100 : ")
        print()
        c.execute("insert into data values('{}',{},{},{},{},{})".format(user,st,ch,vi,au,en))
        os.system('cls')

    t = st + ch + vi + au + en
    l = [t,st,ch,vi,au,en]
    return l


def scoring():
    d = check_user()
    print("Please give all the scores out of 100.\n")
    usp = int_input("it's score for the plot : ")
    ucp = int_input("it's score for the characters : ")
    uvp = int_input("it's score for the visuals : ")
    uap = int_input("it's score for the audio : ")
    uep = int_input("it's score for the enjoyment value : ")
    print()

    sp = (usp*d[1])/d[0]
    cp = (ucp*d[2])/d[0]
    vp = (uvp*d[3])/d[0]
    ap = (uap*d[4])/d[0]
    ep = (uep*d[5])/d[0]

    score = sp + cp + vp + ap + ep
    print("Your score is : ", int(score))

con = True
while con == True :    
    scoring()
    while True:
        x = input("You want to rate anything else? : ")
        if x.lower() == "yes":
            os.system("cls")
            con = True
            break
        elif x.lower() == "no":
            con = False
            break
        else:
            print("Please enter yes or no.")

db.commit()
