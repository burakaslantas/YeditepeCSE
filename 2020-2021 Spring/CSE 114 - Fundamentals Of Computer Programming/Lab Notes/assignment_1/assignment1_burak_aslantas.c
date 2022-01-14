#include <stdio.h>

float calculateAccelerationTime (float acceleration_of_athlete, float top_speed_of_athlete){
    return (top_speed_of_athlete / acceleration_of_athlete);
}

float calculateDistanceAccelerating (float acceleration_of_athlete, float acceleration_time){
    return ((acceleration_of_athlete * acceleration_time * acceleration_time)/2);
}

float calculateTimeTopSpeed (float top_speed_of_athlete, float remaining_distance){
    return (remaining_distance / top_speed_of_athlete);
}

int findWinner (int race_length, float acc_athlete_1, float ts_athlete_1, float acc_athlete_2, float ts_athlete_2){
    //athlete 1 variables
    float acc_time_athlete_1 = calculateAccelerationTime(acc_athlete_1, ts_athlete_1);
    float distance_accelerating_athlete_1 = calculateDistanceAccelerating(acc_athlete_1, acc_time_athlete_1);
    float remaining_distance_athlete_1 = race_length - distance_accelerating_athlete_1;
    float time_top_speed_athlete_1 = calculateTimeTopSpeed(ts_athlete_1, remaining_distance_athlete_1);

    //athlete 2 variables
    float acc_time_athlete_2 = calculateAccelerationTime(acc_athlete_2, ts_athlete_2);
    float distance_accelerating_athlete_2 = calculateDistanceAccelerating(acc_athlete_2, acc_time_athlete_2);
    float remaining_distance_athlete_2 = race_length - distance_accelerating_athlete_2;
    float time_top_speed_athlete_2 = calculateTimeTopSpeed(ts_athlete_2, remaining_distance_athlete_2);

    //total times of athletes
    float total_time_athlete_1 =
            acc_time_athlete_1 +
            time_top_speed_athlete_1;
    float total_time_athlete_2 =
            acc_time_athlete_2 +
            time_top_speed_athlete_2;

    if (total_time_athlete_1 == total_time_athlete_2){
        return 0;
    }
    else if (total_time_athlete_2 > total_time_athlete_1){
        return 1;
    }
    return 2;
}

int main(){
    int race_length, result;
    float acc_athlete_1, ts_athlete_1, acc_athlete_2, ts_athlete_2;

    printf("Enter the length of the race:\n");
    scanf(" %d", &race_length);
    printf("Enter the acceleration of athlete 1:\n");
    scanf(" %f", &acc_athlete_1);
    printf("Enter the top speed of athlete 1:\n");
    scanf(" %f", &ts_athlete_1);
    printf("Enter the acceleration of athlete 2:\n");
    scanf(" %f", &acc_athlete_2);
    printf("Enter the top speed of athlete 2:\n");
    scanf(" %f", &ts_athlete_2);

    result = findWinner(race_length, acc_athlete_1, ts_athlete_1, acc_athlete_2, ts_athlete_2);
    if (result > 0){
        printf("Winner is athlete %d\n", result);
    }
    else {
        printf("There is no winner, tie.\n");
    }
    return 0;
}
