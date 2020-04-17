import traffic
import vehicle
import unittest


class knownCarValues(unittest.TestCase):
    horsepower = 1
    max_speed = 90
    speed = 0
    rated_passenger_capacity = 6
    actual_passenger = 3
    knownGetOnValues = ((1,4),
                        (2,5))

    knownGetOffValues = ((1,2),
                        (3,0))
    def test_get_on(self):
        for get_on_number, known_result in self.knownGetOnValues:
            testCar = vehicle.car("testCar", self.horsepower,self.max_speed,self.speed,self.rated_passenger_capacity,self.actual_passenger)
            testCar.get_on(get_on_number)
            final_passenger = testCar.get_actual_passenger()
            self.assertEqual(final_passenger, known_result)
    def test_get_off(self):
        for get_off_number , known_result in self.knownGetOffValues:
            testCar = vehicle.car("testCar",self.horsepower,self.max_speed,self.speed,self.rated_passenger_capacity,self.actual_passenger)
            testCar.get_off(get_off_number)
            final_passenger = testCar.get_actual_passenger()
            self.assertEqual(final_passenger,known_result)
class knownTruckValues(unittest.TestCase):
    horsepower = 1
    max_speed = 90
    speed = 0
    rated_load = 100
    actual_load = 50
    knownLoadingValues = ((10,60),
                            (5,55))
    knownUnloadingValues = ((10,40),
                            (50,0))
    
    def test_loading(self):
        for additional_load , known_result in self.knownLoadingValues:
            testTruck = vehicle.truck("testTruck",self.horsepower,self.max_speed,self.speed,self.rated_load,self.actual_load)
            print("Test truck currently has %dkg of load and its max load is %dkg" %(testTruck.actual_load,testTruck.rated_load))
            testTruck.loading(additional_load)
            final_load = testTruck.actual_load
            self.assertEqual(final_load,known_result)
    def test_unloading(self):
        for unload_amount , known_result in self.knownUnloadingValues:
            testTruck  = vehicle.truck("testTruck",self.horsepower,self.max_speed,self.speed,self.rated_load,self.actual_load)
            testTruck.unloading(unload_amount)
            final_load = testTruck.actual_load
            self.assertEqual(final_load,known_result)
class knownVehicleValues(unittest.TestCase):
    max_speed = 90
    horsepower = 10
    knownSpeedUpValues =   ((0,10),
                            (2,12),
                            (88,90),
                            (90,90))
    knownSpeedDownValues = ((50,40),
                            (110,100),
                            (5,0),
                            (-1,0))
    knownOverspeedValues = ((0,False),
                            (max_speed,False),
                            (max_speed+1,True))
    def test_speed_up(self):

        ''' speed_up should return known outputs'''
        for initial_speed , known_result in self.knownSpeedUpValues:
            #create test vehicle called "test drive"
            #print("Testing speed up value from %d km/h" %(initial_speed))
            testDrive = vehicle.vehicle('testDrive',self.horsepower,self.max_speed,initial_speed)
            testDrive.speed_up()
            final_speed = testDrive.get_speed()
            self.assertEqual(final_speed,known_result)
    def test_speed_down(self):
        '''speed_down shoudl return known outputs'''
        for initial_speed, known_result in self.knownSpeedDownValues:
            #creat test vehicle called "test drive"
            #print("Testing speed down from: %d km/h" %(initial_speed))
            testDrive = vehicle.vehicle("testDrive",self.horsepower,self.max_speed,initial_speed)
            testDrive.speed_down()
            final_speed = testDrive.get_speed()
            self.assertEqual(final_speed,known_result)
    def test_overspeed(self):
        for test_speed, KnownResult in self.knownOverspeedValues:
            #create test vehicle
            testDrive = vehicle.vehicle("testDrive",self.horsepower,self.max_speed,test_speed)
            print("Testing if %d is overspeed for testDrive of max speed %d" %(test_speed,testDrive.max_speed))
            functionResult = testDrive.is_overspeed()
            self.assertIs(functionResult, KnownResult)

class vehicleBadInput(unittest.TestCase):
    def test_negative_horsepower(self):
        '''should raise error if horsepower becomes negative'''
        self.assertRaises(vehicle.OutOfRangeError ,vehicle.vehicle.get_horsepower, vehicle.vehicle("test",-1,10,5))
    def test_negative_speeds(self):
        '''should raise error if max speed or speed is negative'''
        self.assertRaises(vehicle.OutOfRangeError , vehicle.vehicle.get_speed,vehicle.vehicle("test",10,10,-1))
        self.assertRaises(vehicle.OutOfRangeError, vehicle.vehicle.get_max_speed, vehicle.vehicle('test',3,-1,2))

class truckBadInput(unittest.TestCase):
    def test_negative_load(self):
        '''should raise error for negative load'''
        self.assertRaises(vehicle.OutOfRangeError,vehicle.truck.get_actual_load,vehicle.truck('test',10,10,10,5,-1))
        self.assertRaises(vehicle.OutOfRangeError,vehicle.truck.get_rated_load, vehicle.truck('test',1,10,0,-1,0))
    def test_over_unload(self):
        testTruck = vehicle.truck("testTruck",1,90,0,100,50)
        print("Unloading should raise error if unloading more than actual load (not possible)")
        self.assertRaises(vehicle.OutOfRangeError, testTruck.unloading, 60 )

class carBadInput(unittest.TestCase):
    def test_negative_passenger(self):
        '''shoudl raise error on negative passenger parameters'''
        self.assertRaises(vehicle.OutOfRangeError, vehicle.car.get_rated_passenger_capacity,vehicle.car('test',1,10,0,-1,0))
        self.assertRaises(vehicle.OutOfRangeError,vehicle.car.get_actual_passenger,vehicle.car('test',1,10,0,0,-1))

        testCar = vehicle.car("testCar", 1,90,0,5,3)
        self.assertRaises(vehicle.OutOfRangeError, testCar.get_off, -1)
        self.assertRaises(vehicle.OutOfRangeError, testCar.get_off, 4)


#run all tests
if __name__ == "__main__":
    unittest.main()