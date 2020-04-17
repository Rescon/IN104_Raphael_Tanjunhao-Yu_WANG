import vehicle


def traffic(trucks, cars):
    for truck in trucks:
        name = truck.get_name()
        speed = truck.get_speed()
        load = truck.get_actual_load()
        flag = 1

        print(name + " travels at a speed of " + str(speed) + " km/h with " + str(load) + " kg of cargo.")

        if truck.is_overspeed():
            while not truck.is_stop():
                truck.speed_down()
            print(name + " stops.")
            print(name + " is fined for over speeding.")
            flag = 0

        if truck.is_overload():
            if flag:
                print(name + " stops.")
                while not truck.is_stop():
                    truck.speed_down()
            print(name + " is fined for overloading cargo.")

            num = truck.actual_load - truck.rated_load
            truck.unloading(num)
            print(name + " unloads " + str(num) + " kg of cargo.")

        while not truck.is_full_speed():
            truck.speed_up()
        print(name + " increases its speed to full speed.")

        speed = truck.get_speed()
        load = truck.get_actual_load()
        print(name + " travels at a speed of " + str(speed) + " km/h with " + str(load) + " kg of cargo.")
        print()

    for car in cars:
        name = car.get_name()
        speed = car.get_speed()
        passenger = car.get_actual_passenger()
        flag = 1

        print(name + " travels at a speed of " + str(speed) + " km/h with " + str(passenger) + " passengers.")

        if car.is_overspeed():
            while not car.is_stop():
                car.speed_down()
            print(name + " stops.")
            print(name + " is fined for over speeding.")
            flag = 0

        if car.is_overload():
            if flag:
                print(name + " stops.")
                while not car.is_stop():
                    car.speed_down()
            print(name + " is fined for overloading passengers.")

            num = car.actual_passenger - car.rated_passenger_capacity
            car.get_off(num)

            if num == 1:
                print(str(num) + " people gets off the " + name + ".")
            else:
                print(str(num) + " people get off the " + name + ".")

        while not car.is_full_speed():
            car.speed_up()
        print(name + " increases its speed to full speed.")

        speed = car.get_speed()
        passenger = car.get_actual_passenger()
        print(name + " travels at a speed of " + str(speed) + " km/h with " + str(passenger) + " people.")
        print()


if __name__ == '__main__':

    truck1 = vehicle.truck("truck1", 15, 120, 90, 50, 100)
    truck2 = vehicle.truck("truck2", 20, 100, 120, 80, 80)
    trucks = [truck1, truck2]

    car1 = vehicle.car("car1", 30, 120, 150, 15, 12)
    car2 = vehicle.car("car2", 40, 180, 100, 5, 6)
    cars = [car1, car2]

    traffic(trucks, cars)