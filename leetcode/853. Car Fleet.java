import java.util.*;

class Solution {
    public class Car {
      int position;
      int speed;

      public Car(int position, int speed) {
        this.position = position;
        this.speed = speed;
      }
    }
    
    public class CarComparatorByPosition implements Comparator<Car> {
      @Override
      public int compare(Car c1, Car c2) {
        return Integer.compare(c2.position, c1.position);
      }
    }

    public int carFleet(int target, int[] position, int[] speed) {
      List<Car> cars = new ArrayList<Car>();

      for (int i=0; i<position.length; ++i) {
        cars.add(new Car(position[i], speed[i]));
      }

      Collections.sort(cars, new CarComparatorByPosition());

      float maxTimeToReachDestination = 0;
      int totalFleets = 0;

      for (int i=0; i<cars.size(); ++i) {
        Car c = cars.get(i);
        float timeToReachDestination = (target - c.position) / (float) c.speed;
        if (maxTimeToReachDestination < timeToReachDestination) {
          maxTimeToReachDestination = timeToReachDestination;
          totalFleets++;
        }
      }

      return totalFleets;
    }
}
