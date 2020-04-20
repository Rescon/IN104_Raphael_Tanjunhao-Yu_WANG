import unittest
import animal


class MyTestCase_Predator(unittest.TestCase):
    # Define the cases for the test
    # Weight < , = and > 40
    TestCase_fight = ((30, 50, False),
                      (40, 50, False),
                      (50, 50, True))
    # Speed < , = and > 30
    TestCase_chase = ((50, 20, False),
                      (50, 30, False),
                      (50, 40, True))

    def test_fight(self):
        # Define the example for the test
        example_Predator = animal.Predator('example_Predator', 40, 30)
        for weight, speed, result in self.TestCase_fight:
            test_Predator = animal.Predator('test_Predator', weight, speed)
            res = test_Predator.fight(example_Predator)
            self.assertEqual(res, result)

    def test_chase(self):
        # Define the example for the test
        example_Prey = animal.Prey('example_Prey', 40, 30)
        for weight, speed, result in self.TestCase_chase:
            test_Predator = animal.Predator('test_Predator', weight, speed)
            res = test_Predator.chase(example_Prey)
            self.assertEqual(res, result)


class MyTestCase_Prey(unittest.TestCase):
    # Define the cases for the test
    # Speed < , = and > 30
    TestCase_run = ((20, 20, False),
                    (20, 30, True),
                    (20, 40, True))
    # Weight < , = and > 40
    TestCase_fight = ((30, 30, False),
                      (40, 30, True),
                      (50, 30, True))

    def test_run(self):
        # Define the example for the test
        example_Predator = animal.Predator('example_Predator', 40, 30)
        for weight, speed, result in self.TestCase_run:
            test_Prey = animal.Prey('test_Prey', weight, speed)
            res = test_Prey.run(example_Predator)
            self.assertEqual(res, result)

    def test_fight(self):
        # Define the example for the test
        example_Predator = animal.Predator('example_Predator', 40, 30)
        for weight, speed, result in self.TestCase_fight:
            test_Prey = animal.Prey('test_Prey', weight, speed)
            res = test_Prey.fight(example_Predator)
            self.assertEqual(res, result)

class animal_BadInput(unittest.TestCase):
    TestCase_weight = (-10, 0)
    TestCase_speed = (-10, 0)

    def test_negative_weight(self):
        """It should raise error for negative weight"""
        for weight in self.TestCase_weight:
            test_animal = animal.animal('test_animal', weight, 20)
            self.assertRaises(animal.OutOfRangeError, animal.animal.getWeight, test_animal)

    def test_negative_speed(self):
        """It should raise error for negative weight"""
        for speed in self.TestCase_speed:
            test_animal = animal.animal('test_animal', 30, speed)
            self.assertRaises(animal.OutOfRangeError, animal.animal.getSpeed, test_animal)


if __name__ == '__main__':
    unittest.main()
