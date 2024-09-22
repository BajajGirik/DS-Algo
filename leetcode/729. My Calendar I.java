import java.util.ArrayList;

class MyCalendar {
  private class Event {
    public int start;
    public int end;

    public Event(int start, int end) {
      this.start = start;
      this.end = end;
    }
  }

  private ArrayList<Event> events;

  private void printEvents() {
    System.out.println("**************************");
    for (Event ele: this.events) {
      System.out.println(ele.start + ", " + ele.end);
    }
    System.out.println("**************************");
  }

  public MyCalendar() {
    this.events = new ArrayList<>();
  }

  private int findNewEventIndex(int target) {
    int start = 0;
    int end = this.events.size();

    while (start < end) {
      int mid = start + (end - start) / 2;
      Event midValue = this.events.get(mid);

      if (midValue.end == target) {
        return mid + 1;
      }

      if (midValue.end > target) {
        end = mid;
      } else {
        start = mid + 1;
      }
    }

    return start;
  }

  private void addAndShiftEvents(int index, Event event) {
    Event prev = event;
    Event temp;

    for (int i=index; i<this.events.size(); ++i) {
      temp = this.events.get(i);
      this.events.set(i, prev);
      prev = temp;
    }

    this.events.add(prev);
  }

  public boolean book(int start, int end) {
    int index = findNewEventIndex(start);
    // System.out.println(index);
    if (index < this.events.size() && this.events.get(index).start < end) {
      return false;
    }

    addAndShiftEvents(index, new Event(start, end));
    // printEvents();
    return true;
  }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */
