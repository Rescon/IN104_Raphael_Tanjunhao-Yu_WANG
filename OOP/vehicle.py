# defines animal as highest superclass
class vehicle:
    def __init__(self, name, horsepower, max_speed, speed):
        self.name = name
        self.horsepower = horsepower
        self.max_speed = max_speed
        self.speed = speed

    def get_name(self):
        return self.name

    def get_horsepower(self):
        return self.horsepower

    def get_speed(self):
        return self.speed

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
        return self.actual_load

    def loading(self, num):
        self.actual_load -= num

    def unloading(self, num):
        self.actual_load += num

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
        return self.actual_passenger

    def get_on(self, num):
        self.actual_passenger -= num

    def get_off(self, num):
        self.actual_passenger += num

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
