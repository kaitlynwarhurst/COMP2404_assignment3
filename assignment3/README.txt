Name: Kaitlyn Warhurst
ID: 101217643

Compilation Instructions: (type into the terminal in the directory containing the files) make

Execution Instructions: ./a3

Files:

The Location class (Entity object): 
Files: Location.h and Location.cc
    Contains map coordinates as well as the street names.

The Order class (Entity object):
Files: Order.h and Order.cc
    Contains information about a customer’s Order from Pierres.

The Entity class (Entity object):
Files: Entity.h and Entity.cc
    Contains Pierres user information - base class for Franchises and Drivers.

The Franchise class (Entity object):
Files: Frachise.h and Franchise.cc
    An Entity representing a Pierres franchise location.

The Driver class (Entity object):
Files: Driver.h and Driver.cc
    An Entity who pickups and delivers Orders.

The Queue class (Container object):
Files: Queue.h and Queue.cc
    A ’first-in first-out’ data structure made from a linked list to store Orders.

The Pierres class.
Files: Pierres.h and Pierres.cc
    Manages the Drivers and Franchises of Pierres.
    Coordinates taking, picking up, and delivering Orders.

The Controller class (Control object):
Files: Controller.h and Controller.cc
    Controls the interaction of Pierres with the View

The View class (Boundary object):
Files: View.h and View.cc
    Provides a user menu, takes input, and gives output.