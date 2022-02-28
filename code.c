#include <stdio.h>
#include <time.h>

typedef struct{
	int year;
	int month;
	int day;
} timeinfo;

time_t StartBooking(timeinfo StartDay)
{
	struct tm timeinfo;
    timeinfo.tm_hour = 0;
    timeinfo.tm_min = 0;
    timeinfo.tm_sec = 0;
    timeinfo.tm_year = StartDay.year - 1900;
    timeinfo.tm_mon = StartDay.month - 1;
    timeinfo.tm_mday = StartDay.day;
    
    time_t beginning = mktime(&timeinfo);
    return beginning;
}

time_t EndOfBooking(timeinfo EndDay)
{
	struct tm timeinfo;
    timeinfo.tm_hour = 0;
    timeinfo.tm_min = 0;
    timeinfo.tm_sec = 0;
    timeinfo.tm_year = EndDay.year - 1900;
    timeinfo.tm_mon = EndDay.month - 1;
    timeinfo.tm_mday = EndDay.day;
    
    time_t end = mktime(&timeinfo);
    return end;
}

int main()
{
	timeinfo StartDay;
	printf("Start booking...\n");
	printf("Year : ");
	scanf("%d",&StartDay.year);
	printf("Month : ");
	scanf("%d",&StartDay.month);
	printf("Day : ");
	scanf("%d",&StartDay.day);
    time_t beginning = StartBooking(StartDay);
    
    timeinfo EndDay;
	printf("End of booking...\n");
	printf("Year : ");
	scanf("%d",&EndDay.year);
	printf("Month : ");
	scanf("%d",&EndDay.month);
	printf("Day : ");
	scanf("%d",&EndDay.day);
    time_t end = EndOfBooking(EndDay);

    double diff = difftime(end, beginning);
    int day = diff/86400;
    
    printf("\t\t   ---- receipt ----\n");
    printf("   - Start Booking \t%s", ctime(&beginning));
    printf("   - End of Boooking\t%s", ctime(&end));
    printf("You have reserved a room for %d days, price %d baht", day, day*120);
	return 0;
}
