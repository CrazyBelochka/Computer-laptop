import math
import unittest
import datetime as dt
from datetime import date
from datetime import datetime
from datetime import time
from array import *
#from dateutil import parser

class Human():
    def __init__(self, name, age, weight, food, calfood, normcal, money, allmoney,
                 cal_in_day, money_in_day, money_remained, day, month, year, weekmoney):
        self.name = name
        self.age = age
        self.weight = weight
        self.money = money
        self.food = food
        self.calfood = calfood
        self.allmoney = allmoney
        self.normcal = normcal
        self.cal_in_day = cal_in_day
        self.money_in_day = money_in_day
        self.money_remained = money_remained
        self.day = day
        self.month = month
        self.year = year
        self.weekmoney = weekmoney


    def showall(myArray):
        for i in range(0, len(myArray)):
            print(myArray[i].name)

    def addrecord(myArray):
        print(f'Укажите количество человечков: ')
        count = int(input())
        for i in range(1, count + 1):
            print(f'Введите сегодняшнюю дату(день.месяц.год): ')
            date_format = '%d.%m.%Y'
            date_format = input()
            day, month, year = map(int, date_format.split('.'))
            print(f'Введите ваше имя, возраст и вес: ')
            print(f'Имя: ')
            name = str(input())
            print(f'Возраст: ')
            age = int(input())
            print(f'Вес: ')
            weight = int(input())
            print(f'Напишите, что вы покушали:')
            food = str(input())
            calfood = float(CaloriesCalculator.DefineCalories(food))
            print(f'Сколько вы накушали калорий за выбранную еду: ')
            print(calfood)
            print(f'Сколько вам осталось покушать в течении дня: ')
            normcal = weight / age * 1000
            cal_in_day = normcal - calfood
            print(cal_in_day)
            print(f'Напишите, сколько вы готовы тратить на еду в день: ')
            money_in_day = int(input())
            print(f'Напишите, сколько вы потратили на покушать: ')
            money_meal = int(input())
            money_remained = money_in_day
            weekmoney = money_meal
            money_remained = money_remained - money_meal
            allmoney = 0
            allmoney = allmoney + money_meal
            print(f'Вот сколько вы потратили на покушать в общем: ')
            print(allmoney)
            myArray.append(Human(name, age, weight, food, calfood, normcal, money_meal, allmoney,
                                 cal_in_day, money_in_day, money_remained, day, month, year, weekmoney))

    def show(self):
        print(f'Имя: ', self.name, f' Возраст: ', self.age, f' Вес: ', self.weight)
        print(f'Нормальное число калорий в день: ', self.normcal)

    def checknames(myArray):
        print(f'Введите Имя, которое мы поищем в памяти')
        name = str(input())
        b = 1
        for i in range(0, len(myArray)):
            if (myArray[i].name == name):
                print(f'Все удачно, что хотите сделать: ')
                a = 1
                while (a == 1):
                    print(f'1 - Показать информацию о человечке:', '2 - Добавить прием пищи:',
                          '3 - Удалить', '4 - Посмотреть, сколько денег осталось на сегодняшний день: ',
                          '5 - Показать всех человечков',  '9 - Выход', sep='\n')
                    number = int(input())
                    if (number == 1):
                        CashCalculator.get_today_status(name, myArray)
                        b = 0
                    if (number == 2):
                        CaloriesCalculator.new_meal(name, myArray, i)
                        b = 0
                    if (number == 3):
                        Human.delete_info(name, myArray)
                        b = 0
                        break
                    if (number == 4):
                        CashCalculator.get_today_cash_remained(name, myArray)
                        b = 0
                    if (number == 5):
                        Human.showall(myArray)
                    if (number == 9):
                        b = 0
                        break
        if (b == 1):
            print(f'Такого человечка мы не смогли найти в памяти, проверьте правильность написания имени: ')

    def delete_info(name, myArray):
        for i in range(0, len(myArray)):
            if (myArray[i].name == name):
                myArray[i].name = "ghfbldhfbglfdgbdjgbdlfgk"


class Calculator(Human):
    def __init__(self, money, cal):
        self.money = money
        self.cal = cal


class CaloriesCalculator(Calculator):
    def __init__(self, food, amount, money, cal):
        super().__init__(money, cal)
        self.food = food
        self.amount = amount

    def DefineCalories(self):
       return {
           'Мясо':800,
           'Орехи':1000,
           'Шоколад':500,
           'Салат':200,
           'Вода':100,
           'Сок':300

        }[self]

    def new_meal(name, myArray, count):
                print(f'Введите сегодняшнюю дату(день.месяц.год): ')
                date_format = '%d.%m.%Y'
                date_format = input()
                day, month, year = map(int, date_format.split('.'))

                if(myArray[count].year == year and myArray[count].month == month and
                        ((myArray[count].day - day <= 7) or (day - myArray[count] <= 7))):
                    print(f'За эту неделю вы уже кушали')
                    print(f'Напишите, что вы покушали:')
                    myArray[count].food = str(input())
                    myArray[count].calfood = float(CaloriesCalculator.DefineCalories(myArray[count].food))
                    print(f'Сколько вы накушали калорий за выбранную еду: ')
                    print(myArray[count].calfood)
                    print(f'Сколько вам осталось покушать в течении дня: ')
                    myArray[count].normcal = myArray[count].weight / myArray[count].age * 1000
                    myArray[count].cal_in_day = myArray[count].cal_in_day - myArray[count].calfood
                    print(myArray[count].cal_in_day)
                    print(f'Напишите, сколько вы потратили на покушать: ')
                    myArray[count].money_meal = int(input())
                    myArray[count].money_remained = myArray[count].money_remained - myArray[count].money_meal
                    myArray[count].weekmoney = myArray[count].weekmoney + myArray[count].money_meal
                    myArray[count].allmoney = myArray[count].allmoney + myArray[count].money_meal
                    print(f'Вот сколько вы потратили на покушать за одну неделю:')
                    print(myArray[count].weekmoney)
                    print(f'---------------------------------------------------------')
                else:
                    name = myArray[count].name
                    age = myArray[count].age
                    weight = myArray[count].weight

                    print(f'Напишите, что вы покушали:')
                    food = str(input())
                    calfood = float(CaloriesCalculator.DefineCalories(food))
                    print(f'Сколько вы накушали калорий за выбранную еду: ')
                    print(calfood)
                    print(f'Сколько вам осталось покушать в течении дня: ')
                    normcal = myArray[count].weight / myArray[count].age * 1000
                    cal_in_day = normcal - calfood
                    print(cal_in_day)
                        #print(f'Напишите, сколько вы готовы тратить на еду в день: ')
                    money_in_day = myArray[count].money_in_day
                    print(f'Напишите, сколько вы потратили на покушать: ')
                    money_meal = int(input())
                    money_remained = money_in_day
                    weekmoney = money_meal
                    money_remained = money_remained - money_meal
                    allmoney = money_meal
                    myArray.append(Human(name, age, weight, food, calfood, normcal, money_meal, allmoney,
                                             cal_in_day, money_in_day, money_remained, day, month, year, weekmoney))




class CashCalculator(Calculator):
    def __init__(self, money, allmoney):
        self.money = int(money)
        self.allmoney = int(allmoney)

    def SummWaste(self):
        self.allmoney = self.allmoney + self.money
        return(self.allmoney)

    def get_today_status(name, myArray):
        for i in range(0, len(myArray)):
            if (myArray[i].name == name):
                print('Имя: ', myArray[i].name, 'Возраст: ', myArray[i].age, 'Вес: ', myArray[i].weight,
                      'Сколько осталось накушать калорий в течении дня: ', myArray[i].cal_in_day,
                      'Сколько затрачено денег: ', myArray[i].allmoney,  sep='\n')
                print()
                print(f'---------------------------------------------------------')

    def get_week_status(name, myArray):
        print()

    def get_today_cash_remained(name, myArray):
        for i in range(0, len(myArray)):
            if (myArray[i].name == name):
                print(f'Вот сколько денежек у вас осталось на данный момент, до конца этого дня: ')
                print(myArray[i].money_remained)




class Main:
    myArray = []
    while(1):
        print(f'           Калькулятор денег и калорий           ')
        print('1 - Добавить новых людей:', '2 - Поботать уже с существующими челиками: ',
              '3 - Выход', sep='\n')
        number = int(input())
        if (number == 1):
            Human.addrecord(myArray)  # Новые люди
        if (number == 2):
            CashCalculator.checknames(myArray) # Работа с базой данных уже существующих
        if (number == 3):
            exit()









