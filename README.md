# DS_Project_CMP_1ST_YEAR :fire::collision: 
### Eat and  Fly :pizza::hamburger::fork_and_knife:
#### It is a program  coded with C++ using Data structures and Algorthims to bulid a simulation to a restaurant system that will help the mangers of the restaurant to manage , get statistics to the income of the restaurant and  helping them improving the service 
# Description:
- **This program is simulation to restaurant that has four regions ,every region has three types of orders: VIP ,Frozen and Normal ordres and three types of motorcycles as the orders**
   1. **VIP orders: they are the orders for VIP persons and it has priority depending on the distance between the restaurant and the client , the money that is payed for the order and the arrivial time of the order and the more priority is the less waiting  time that will take and any motos can deliver this order.**
   2. **Frozen orders: they are the order that has a special motorcycle to be assign in , frozen motos have  small refrigerator to save the food so the frozen orders won't be assign in any other motos.**
   3. **Normal orders: they are the usual orders they have no restrictions and they can be assign in any type of motos except the frozen ones**
- **This prorgram has three Events Arrival_Event , cancellation_Event and promtion_Event**
   1. **Arrival_Event: It is the Event when the order reaches the restaurant then it enters its region and put with its type**
   2. **cancellation_Event: It is the event that cancel an order "No oreder can be cancelled if it is assigned in a moto ".**
   3. **Promotion_Event: It is the Event that promote the Normal order to a VIP order if the client pays extra money "the order will be promoted automaticllay if its wating time exceeds a certain time".**
- **This program consists of three modes: StepByStep mode  , silent mode and interactive mode**
    1. StepByStep: Here  every 2 seconds  the  system will allow the active orders to be assign in the available motorcycles , the program will be excuted by itself without any entring from the user , what happened will be displayed on the screen  and the statistics will be displayed and saved in the output file .
    2. silent: Here the program will be excuted silently , the user won't see what happen by the GUI but the statistics will be showed in the output file .
    3. Interactive: Here the system is totally controlled by the user he/she will allow the active orders to be assing at motorcycle in the time he/she wants , the program will be excuted and show what happened in the current time ,every assinging  ,cancellation, promotion and arriving will be display in the GUI and the statistics will be displayed and saved in the output file .  
