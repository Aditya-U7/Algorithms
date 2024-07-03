def check_start_time(start_time):
    
    if start_time >= 0:
        return True
    else:
        return False    


def check_finish_time(st, ft):
    
    if ft >= st:
        return True
    else:
        return False


def activity_selector(activity, activity_count):

    selected_activities = []
    
    for key, value in activity_count.items():
    
        if selected_activities:
            
            if activity[key][0] >= activity[selected_activities[-1]][1]:
                
                selected_activities.append(key)
        else:
            
            selected_activities.append(key)
    
    if selected_activities:
        print('\n\nThe following activities will be selected: ') 
    
    for act in selected_activities:
        print(act)
    
###################

no_of_act = int(input('Enter the number of activities: '))

activity = {}
activity_count = {}
activity_no = 1

while (no_of_act):
    
    start_time = int(input('Enter a valid start time: '))
    
    while not check_start_time(start_time):
        
        start_time = int(input('Re-enter a valid start time: '))
        
    finish_time = int(input('Enter a valid finish time: '))    
    
    while not check_finish_time(start_time, finish_time):
    
        finish_time = int(input('Re-enter a valid finish time: ')) 
    
    activity[activity_no] = (start_time, finish_time)
    activity_count[activity_no] = finish_time
    
    activity_no += 1
    
    no_of_act -= 1

activity_count = dict(sorted(activity_count.items(), key=lambda value: value[1]))

activity_selector(activity, activity_count)

       
