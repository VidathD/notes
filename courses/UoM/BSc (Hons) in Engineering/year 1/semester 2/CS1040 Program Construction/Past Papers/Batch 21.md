# Batch 21 (2023)

## Question 1

### Part C

1. During compile time, no physical memory is used. However, the compiler does type checking and note that `int i` will require 4 bytes are `Integer intObj` will require a 4 byte reference. This information is stored in the bytecode.
2. During runtime, setting `i=123` will store the value directly in the stack using 4 bytes. `intObj=new Integer(123)` will use 4 bytes in the stack to store the reference to the location in heap memory where 16 bytes will be used to store the value as an integer object.

## Question 2

### Part A

1. Overloading
2. Overriding

### Part B

Create an abstract class called `menuItem` that contains state variables for `price` and `itemID`. It should also include the constructor and common methods `getItemId`, `getPrice`, `setPrice` and an abstract method `serve`. Create an abstract class `foodItem` that inherits from `menuItem` and adds the state variable `shelfLife` and the method `getShelfLife`. Create an interface `caramalisable` that requires the `addCaramel` method. Create concrete class `Coffee` by extending `menuItem` and implementing `caramalisable`. Create `Doughtnut` by extending `foodItem` and implementing `caramalisable`. Create `Sandwitch` by extending `foodItem`. 

### Part C

Polymorphism establishes an “is a” relationship and allows a parent to represent the many forms of its children. Here, if we store the ordered objects in a `List<menuItem>` and iterate over it and call the `.serve()` method on each object, dynamic binding enabled by polymorphism will ensure that `Coffee` outputs `"I am served in a cup!"` while `Doughnut` and `Sandwich` will output `"I am served on a plate!"`, which shows that the parent `menuItem` class is representing all of its children classes and selecting the suitable method depending on the current child.

### Part D

The state variables are set to public. However, since there are getters and setters defined, we can use the concept of encapsulation and set those variables to private. Then the state variables can be only accessed and changed using the designated getters and setters which enforce validation and data integrity.

### Part E

```java
abstract class MenuItem {  
    private double price;  
    private int itemId;  
  
    public MenuItem(int itemId, double price) {  
        this.itemId = itemId;  
        this.price = price;  
    }  
  
    public void setPrice(double price) {  
        this.price = price;  
    }  
  
    public int getitemId() {  
        return this.itemId;  
    }  
  
    // The original code doesn't have a getPrice method, but it seems pretty important so I added it  
    public double getPrice() {  
        return this.price;  
    }  
  
    public abstract String serve();  
}  
  
abstract class FoodItem extends MenuItem {  
    private int shelfLife;  
  
    public FoodItem(int itemId, double price, int shelfLife) {  
        super(itemId, price);  
        this.shelfLife = shelfLife;  
    }  
  
    public int getShelfLife() {  
        return this.shelfLife;  
    }  
  
    @Override  
    public String serve() {  
        return "I am served on a plate!";  
    }  
}  
  
interface Caramelisable {  
    String addCaramel();  
}  
  
class Coffee extends MenuItem implements Caramelisable {  
    public Coffee(int itemId, double price) {  
        super(itemId, price);  
    }  
  
    @Override  
    public String serve() {  
        return "I am served in a cup!";  
    }  
  
    @Override  
    public String addCaramel() {  
        return "I am now a caramel coffee!";  
    }  
}  
  
class Doughnut extends FoodItem implements Caramelisable {  
    public Doughnut(int itemId, double price) {  
        super(itemId, price, 2); // Shelf life 2 days  
    }  
  
    @Override  
    public String addCaramel() {  
        return "I am now a caramel doughnut!";  
    }  
}  
  
class Sandwich extends FoodItem {  
    public Sandwich(int itemId, double price) {  
        super(itemId, price, 1); // Shelf life 1 day  
    }  
}
```

## Question 3

### Part A

All

### Part B

```java
import java.util.ArrayList;  
import java.util.List;  
  
// Print Job Class  
class PrintJob {  
    private int jobId;  
  
    public PrintJob(int jobId) {  
        this.jobId = jobId;  
    }  
  
    public int getJobId() {  
        return jobId;  
    }  
}  
  
// Shared Queue class  
class SharedQueue {  
    private List<PrintJob> printjobs;  
    private int capacity;  
  
    public SharedQueue(int capacity) {  
        this.capacity = capacity;  
        this.printjobs = new ArrayList<>();  
    }  
  
    // Method to add print jobs to the shared queue  
    public synchronized void addPrintJobs(PrintJob printjob) {  
        while (printjobs.size() == capacity) {  
            try {  
                wait();  
            } catch (InterruptedException e) {  
                Thread.currentThread().interrupt();  
            }  
        }  
        printjobs.add(printjob);  
        notifyAll();  
    }  
  
    // Method to get print jobs out of the shared queue to process  
    public synchronized PrintJob getPrintJob() {  
        while (printjobs.isEmpty()) {  
            try {  
                wait();  
            } catch (InterruptedException e) {  
                Thread.currentThread().interrupt();  
            }  
        }  
        PrintJob printjob = printjobs.remove(0);  
        notifyAll();  
        return printjob;  
    }  
}  
  
// The Computer Class  
class Computer implements Runnable {  
    private SharedQueue sharedqueue;  
    private int currentPrintJobId;  
    private int id;  
  
    public Computer(SharedQueue sharedqueue, int id) {  
        this.sharedqueue = sharedqueue;  
        this.currentPrintJobId = 0;  
        this.id = id;  
    }  
  
    @Override  
    public void run() {  
        try {  
            while (true) {  
                // Simulating print document creation  
                Thread.sleep(1000);  
                PrintJob printjob = new PrintJob(id + currentPrintJobId);  
                currentPrintJobId++;  
                sharedqueue.addPrintJobs(printjob);  
            }  
        } catch (InterruptedException e) {  
            Thread.currentThread().interrupt();  
        }  
    }  
}  
  
// The Printer Class  
class Printer implements Runnable {  
    private SharedQueue sharedqueue;  
    private int id;  
  
    public Printer(SharedQueue sharedqueue, int id) {  
        this.sharedqueue = sharedqueue;  
        this.id = id;  
    }  
  
    @Override  
    public void run() {  
        try {  
            while (true) {  
                PrintJob printjob = sharedqueue.getPrintJob();  
                // Simulating time taken by printer to do the job  
                System.out.println("Printer " + id + " is processing print job id " + printjob.getJobId());  
                Thread.sleep(2000);  
            }  
        } catch (InterruptedException e) {  
            Thread.currentThread().interrupt();  
        }  
    }  
}  
  
// The Main class  
public class Main {  
    public static void main(String[] args) {  
        // Create a shared queue with a capacity of 5  
        SharedQueue sharedqueue = new SharedQueue(5);  
  
        for (int i = 1; i <= 3; i++) {  
            new Thread(new Computer(sharedqueue, i)).start();  
        }  
        for (int i = 1; i <= 2; i++) {  
            new Thread(new Printer(sharedqueue, i)).start();  
        }  
    }  
}
```

### Part C

```java
class PrintJob {  
    private int jobId;  
  
    public PrintJob(int jobId, String fileType) throws TypeNotSupportedException {  
        if (!(fileType.equalsIgnoreCase("pdf") || fileType.equalsIgnoreCase("txt"))) {  
            throw new TypeNotSupportedException("File type '" + fileType + "' is not supported by printers.");  
        }  
        this.jobId = jobId;  
    }  
  
    public int getJobId() {  
        return jobId;  
    }  
}

class Computer implements Runnable {  
    private SharedQueue sharedqueue;  
    private int currentPrintJobId;  
    private int id;  
  
    public Computer(SharedQueue sharedqueue, int id) {  
        this.sharedqueue = sharedqueue;  
        this.currentPrintJobId = 0;  
        this.id = id;  
    }  
  
    @Override  
    public void run() {  
        try {  
            while (true) {  
                // Simulating print document creation  
                Thread.sleep(1000);  
                // Simulating alternate extensions to test exception handling safely  
                String ext="pdf";  
                if (currentPrintJobId % 5 == 0){  
                    ext="exe";  
                }  
                try {  
                    PrintJob printjob = new PrintJob(id + currentPrintJobId, ext);  
                    sharedqueue.addPrintJobs(printjob);  
                } catch (TypeNotSupportedException e) {  
                    System.err.println("Computer " + id + " failed to create print job: " + e.getMessage());  
                }  
                currentPrintJobId++;  
            }  
        } catch (InterruptedException e) {  
            Thread.currentThread().interrupt();  
        }  
    }  
}
```

### Part D

1. True
2. True
3. False
4. True
5. True


## Question 4

### Part A

1. Adapter
2. Decorator
3. State
4. Proxy
5. Facade
6. Template Method
7. Factory Method
8. Singleton
9. Composite
10. Strategy
11. Iterator
12. Command
13. Observer

### Part B

1. Builder
    - Builder decouples the step by step construction of an object from its representation. This allows clean construction of combinations including only the parts that are necessary of the meal.

2. Command
    - Command pattern encapsulates the order ensuring the waiter doesn't know the content of the order. Here the client acts as the client, the order as the command, waiter as the invoker and the chef as the receiver.

3. Observer
    - Observer provides a one-to-many relationship where the observer, in this case the server, listens for a change and notifies all the clients.

4. Decorator
    - Since each topping is represented by a different class, we can use them as decorators to add one or more toppings to the base ice cream. Here each decorator class wraps the ice cream class that is given as input and adds the topping to it.


### Part C

