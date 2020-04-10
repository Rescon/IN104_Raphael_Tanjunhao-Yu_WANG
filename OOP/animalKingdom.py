import animal

def encounter(animal1,animal2):
    name1 = animal1.getName()
    name2 = animal2.getName()
    print(name1+" meets "+name2)
    if isinstance(animal1,animal.Predator):
        if isinstance(animal2, animal.Predator):
            #predator 1 will fight predator 2
            print(name1 +" initiates the fight")
            result = animal1.fight(animal2)
            if result == False:
                print(name1 +" lost the fight")
                print(name2 +" ate " +name1)
            else:
                print(name1 +" overpowered" +name2)
                print(name1 +"ate " +name2)
        if isinstance(animal2,animal.Prey):
            #predator will chase predator 2
            print(name1 +" starts chasing")
            result  = animal1.chase
            if result == True:
                print(name1 +" overpowered the " +name2)
                print(name1 +" ate " +name2)
            else:
                print("But "+name2+" was too fast")
                print(name1 +" left emptyhanded")
    if isinstance(animal1, animal.Prey):
        if isinstance(animal2, animal.Predator):
            print(name1 +" starts running")
            result = animal1.run(animal2)
            if result == True:
                print(name1 +" gets to see another day")
            else:
                print(name1 +" got eaten by "+ name2)
        if isinstance(animal2, animal.Prey):
            print("The 2 animals greeted each other and moved on with their day")


if __name__ == '__main__':
    #initialise afew animals
    wolf = animal.Predator('wolf',30,50)
    bear = animal.Predator('bear',50,30)
    encounter(wolf,bear)
    rabbit = animal.Prey('rabbit',20,50)
    encounter(wolf,rabbit)
    encounter(rabbit,rabbit)
