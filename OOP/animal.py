# Define exceptions
class animalError(Exception): pass
class OutOfRangeError(animalError): pass

# defines animal as highest superclass
class animal:
    def __init__(self, name, weight, speed):
        self.name = name
        self.weight = weight
        self.speed = speed

    def getName(self):
        return self.name

    def getWeight(self):
        if self.weight <= 0:
            print("The weight should be positive.")
            raise OutOfRangeError
        return self.weight

    def getSpeed(self):
        if self.speed <= 0:
            print("The speed should be positive.")
            raise OutOfRangeError
        return self.speed


class Predator(animal):
    # inherit all methods from animal
    def fight(self, otherPredator):
        # fight is won by weight
        target = otherPredator.getWeight()
        if self.weight > target:
            return True
        else:
            return False

    def chase(self, prey):
        target = prey.getSpeed()  # this is the speed to beat to catch prey
        if self.speed > target:
            return True  # true for when chase is successful
        else:
            return False


class Prey(animal):
    def run(self, predator):
        threat = predator.getSpeed()
        if self.speed >= threat:
            return True
        else:
            return False

    def fight(self, predator):
        threat = predator.getWeight()
        if self.weight >= threat:
            return True
        else:
            return False
