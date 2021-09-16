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
                      'Сколько затрачено денег: ', myArray[i].allmoney, 'Дата кушанья: ', myArray[i].date,  sep='\n')
                print()
                print(f'---------------------------------------------------------')

    def get_week_status(name, myArray):
        print()

    def get_today_cash_remained(name, myArray):
        for i in range(0, len(myArray)):
            if (myArray[i].name == name):
                print(f'Вот сколько денежек у вас осталось на данный момент, до конца этого дня: ')
                print(myArray[i].money_remained)
