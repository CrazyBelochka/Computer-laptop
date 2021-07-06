import math
import unittest
import datetime
from array import *


class Human():
    def __init__(self, name, age, weight, food, calfood, normcal, money, allmoney,
                 cal_in_day, money_in_day, money_remained, date_ate):
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
        self.date_ate - date_ate

    def addrecord(myArray):
        print(f'Укажите количество человечков: ')
        count = int(input())
        for i in range(1, count + 1):
            print(f'Введите сегодняшнюю дату(через запятую, год, месяц, день): ')
            date_ate = datetime.date(input()) #надо сделать так, чтобы информацию по дате приема пищи
            # могла быть доступна, так как нужно будет короче формировать инфу по неделе/месяцу

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
            money_remained = money_remained - money_meal
            allmoney = 0
            allmoney = allmoney + money_meal
            print(f'Вот сколько вы потратили на покушать в общем: ')
            print(allmoney)
            myArray.append(Human(name, age, weight, food, calfood, normcal, money_meal, allmoney,
                                 cal_in_day, money_in_day, money_remained, date_ate))

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
                          '3 - Удалить', '4 - Посмотреть, сколько денег осталост на сегодняшний день: ', '9 - Выход', sep='\n')
                    number = int(input())
                    if (number == 1):
                        CashCalculator.get_today_status(name, myArray)
                        b = 0
                    if (number == 2):
                        CaloriesCalculator.new_meal(name, myArray)
                        b = 0
                    if (number == 3):
                        Human.delete_info(name, myArray)
                        b = 0
                        break
                    if (number == 4):
                        CashCalculator.get_today_cash_remained(name, myArray)
                        b = 0
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

    def new_meal(self, name, myArray):
        for i in range(0, len(myArray)):
            if (myArray[i].name == name):
                print(f'Напишите, что вы покушали:')
                myArray[i].food = str(input())
                myArray[i].calfood = float(CaloriesCalculator.DefineCalories(myArray[i].food))
                print(f'Сколько вы накушали калорий за выбранную еду: ')
                print(myArray[i].calfood)
                print(f'Сколько вам осталось покушать в течении дня: ')
                myArray[i].normcal = myArray[i].weight / myArray[i].age * 1000
                myArray[i].cal_in_day = myArray[i].cal_in_day - myArray[i].calfood
                print(myArray[i].cal_in_day)
                print(f'Напишите, сколько вы потратили на покушать: ')
                myArray[i].money_meal = int(input())
                myArray[i].money_remained = myArray[i].money_remained - myArray[i].money_meal
                myArray[i].allmoney = myArray[i].allmoney + myArray[i].money_meal
                print(f'Вот сколько вы потратили на покушать в общем: ')
                print(myArray[i].allmoney)
                print()
                print(f'---------------------------------------------------------')


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
                      'Сколько затрачено денег: ', myArray[i].allmoney, sep='\n')
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









