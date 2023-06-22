#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

// Structure
typedef struct
{
   int entryNo;
   char sensorNo[3];
   char date[11];
   char time[9];
   int light;
   int temperature;
   int humidity;
} LogEntry;

LogEntry logEntries[MAX_ENTRIES];
int numEntries = 0;

void extractDataFromFile(const char *filename)
{
   FILE *file = fopen(filename, "r");
   if (file == NULL)
   {
      printf("Failed to open the file.\n");
      return;
   }

   char line[256];
   fgets(line, sizeof(line), file);

   // Read each line and store it in the array of structures
   while (fgets(line, sizeof(line), file) != NULL)
   {
      LogEntry entry;
      sscanf(line, "%d,%[^,],%[^,],%[^,],%d,%d,%d",
             &entry.entryNo, entry.sensorNo, entry.date, entry.time,
             &entry.light, &entry.temperature, &entry.humidity);
      logEntries[numEntries++] = entry;
   }

   fclose(file);
}

// Function to search log entry with the specified entryNo
void displayLogEntry(int entryNo)
{
   int found = 0;
   for (int i = 0; i < numEntries; i++)
   {
      if (logEntries[i].entryNo == entryNo)
      {
         printf("EntryNo\tSensorNo\tDate\t\tTime\t\tLight\tTemperature\tHumidity\n");
         printf("--------------------------------------------------------------------\n");
         LogEntry entry = logEntries[i];
         printf("%d\t%s\t\t%s\t%s\t%d\t%d\t\t%d\n",
                entry.entryNo, entry.sensorNo, entry.date, entry.time,
                entry.light, entry.temperature, entry.humidity);
         found = 1;
         break;
      }
   }
   if (!found)
   {
      printf("No log entry with EntryNo %d found.\n", entryNo);
   }
}

// Function to all log entries
void displayAllLogEntries()
{
   if (numEntries == 0)
   {
      printf("No log entries available.\n");
      return;
   }

   printf("EntryNo\tSensorNo\tDate\t\tTime\t\tLight\tTemperature\tHumidity\n");
   printf("--------------------------------------------------------------------\n");

   for (int i = 0; i < numEntries; i++)
   {
      LogEntry entry = logEntries[i];
      printf("%d\t%s\t\t%s\t%s\t%d\t%d\t\t%d\n",
             entry.entryNo, entry.sensorNo, entry.date, entry.time,
             entry.light, entry.temperature, entry.humidity);
   }
}

int main()
{
   const char *filename = "data.csv";
   extractDataFromFile(filename);

   int choice;
   printf("Select an option:\n");
   printf("1. Display all log entries\n");
   printf("2. Display a specific log entry\n");
   printf("Enter your choice: ");
   scanf("%d", &choice);

   // 1 to display all log entries
   if (choice == 1)
   {
      displayAllLogEntries();
   }
   // 2 to display specific log entry
   else if (choice == 2)
   {
      int entryNo;
      printf("Enter the EntryNo: ");
      scanf("%d", &entryNo);
      displayLogEntry(entryNo);
   }
   // Invalid choice
   else
   {
      printf("Invalid choice. Exiting...\n");
   }

   return 0;
}


