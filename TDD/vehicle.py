class vehicleError(Exception): pass
class OutOfRangeError(vehicleError): pass

class vehicle:
    def __init__(self, name, horsepower, max_speed, speed):
        self.name = name
        self.horsepower = horsepower
        self.max_speed = max_speed
        self.speed = speed

    def get_name(self):
        return self.name

    def get_horsepower(self):
        if self.horsepower<0:
            raise OutOfRangeError
        return self.horsepower

    def get_speed(self):
        if self.speed <0:
            raise OutOfRangeError
        return self.speed

    def get_max_speed(self):
        if self.max_speed < 0:
            raise OutOfRangeError
        return self.max_speed

    def speed_up(self):
        self.speed += self.horsepower
        if self.speed > self.max_speed:
            self.speed = self.max_speed

    def speed_down(self):
        self.speed -= self.horsepower
        if self.speed < 0:
            self.speed = 0

    def is_overspeed(self):
        if self.speed > self.max_speed:
            return True
        else:
            return False

    def is_stop(self):
        if self.speed == 0:
            return True
        else:
            return False

    def is_full_speed(self):
        if self.speed == self.max_speed:
            return True
        else:
            return False


class truck(vehicle):
    def __init__(self, name, horsepower, max_speed, speed, rated_load, actual_load):
        super().__init__(name, horsepower, max_speed, speed)
        self.rated_load = rated_load
        self.actual_load = actual_load

    def get_actual_load(self):
        if self.actual_load<0:
            raise OutOfRangeError
        return self.actual_load
    
    def get_rated_load(self):
        if self.rated_load<0:
            raise OutOfRangeError
        return self.rated_load

    def loading(self, num):
        self.actual_load += num

    def unloading(self, num):
        #make sure that we even have that much load to unload
        if num > self.actual_load:
            print("Truck does not have that much load")
            raise OutOfRangeError
        self.actual_load -= num

    def is_overload(self):
        if self.actual_load > self.rated_load:
            return True
        else:
            return False

    def is_full(self):
        if self.actual_load == self.rated_load:
            return True
        else:
            return False

    def is_empty(self):
        if self.actual_load == 0:
            return True
        else:
            return False


class car(vehicle):
    def __init__(self, name, horsepower, max_speed, speed, rated_passenger_capacity, actual_passenger):
        super().__init__(name, horsepower, max_speed, speed)
        self.rated_passenger_capacity = rated_passenger_capacity
        self.actual_passenger = actual_passenger

    def get_actual_passenger(self):
        if self.actual_passenger<0:
            raise OutOfRangeError
        return self.actual_passenger

    def get_rated_passenger_capacity(self):
        if self.rated_passenger_capacity<0:
            raise OutOfRangeError
        return self.rated_passenger_capacity

    def get_on(self, num):
        self.actual_passenger += num

    def get_off(self, num):
        if num<0 or num>self.actual_passenger:
            print("Input needs to be postive")
            raise OutOfRangeError
        
        self.actual_passenger -= num

    def is_overload(self):
        if self.actual_passenger > self.rated_passenger_capacity:
            return True
        else:
            return False

    def is_full(self):
        if self.actual_passenger == self.rated_passenger_capacity:
            return True
        else:
            return False

    def is_empty(self):
        if self.actual_passenger == 0:
            return True
        else:
            return False