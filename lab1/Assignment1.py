'''
• Name of program contained in the file: EECS 348 Assignment 1
• Brief description of the program: CEO Email prioritization program
• Inputs: Assignment1_Test_File.txt
• Output:  Next email and number of unread emails
• Author’s full name: Mariska Rai
• Creation date: 08/26/2025
'''
from datetime import datetime
class Email: #starting a email class and assigning the necessary information below
    #assigning self to the object it belongs to below
    def __init__(self, sender, subject, date):
        self.sender = sender
        self.subject = subject
        self.date = date

        #convert the date into a readable  dateime object
        self.date = datetime.strptime(date, "%m-%d-%Y")

        #assign senders into pririoty, I had chatgpt and claude help me with determining the system for this 
        category_priority= {
            "Boss": 5,
            "Subordinate": 4,
            "Peer": 3,
            "ImportantPerson": 2,
            "OtherPerson": 1
        }
        #after translating the strings into numerical it will send it to the category value here
        self.category_value = category_priority[sender]

    def __lt__(self,other):
        







