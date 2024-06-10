#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int counter = 0;
int k = 0;

typedef struct shape
{
    float x[4];
    float y[4];
    int n;
    float area;
    struct shape *next;
} shape;

shape *read(char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file) 
    {
        printf("File could not be opened.\n");
        return NULL;
    }

    shape *head = NULL, *current = NULL;
    char line[256];
    int shape_count = 1;

    while (fgets(line, sizeof(line), file))
     {
        shape *new_shape = (shape *)malloc(sizeof(shape));
        if (strncmp(line, "tx", 2) == 0) 
        {
            sscanf(line, "tx%d,%f,%f,%f", &new_shape->n, &new_shape->x[0], &new_shape->x[1], &new_shape->x[2]);
            fgets(line, sizeof(line), file);
            sscanf(line, "ty%d,%f,%f,%f", &new_shape->n, &new_shape->y[0], &new_shape->y[1], &new_shape->y[2]);
            new_shape->x[3] = new_shape->x[0]; 
            new_shape->y[3] = new_shape->y[0];
        } 
        else if (strncmp(line, "rx", 2) == 0)
        {
            sscanf(line, "rx%d,%f,%f,%f,%f", &new_shape->n, &new_shape->x[0], &new_shape->x[1], &new_shape->x[2], &new_shape->x[3]);
            fgets(line, sizeof(line), file);
            sscanf(line, "ry%d,%f,%f,%f,%f", &new_shape->n, &new_shape->y[0], &new_shape->y[1], &new_shape->y[2], &new_shape->y[3]);
        }
        new_shape->n = shape_count++;
        new_shape->next = NULL;

        if (!head) 
        {
            head = new_shape;
            current = head;
        } 
        else 
        {
            current->next = new_shape;
            current = new_shape;
        }
        
    }

    fclose(file);
    return head;
}

void calc_areas(shape *l)
{
    while (l != NULL) 
    {
        float area = 0;
        for (int i = 0; i < 4; i++) 
        {
            int next = (i + 1) % 4;
            area += l->x[i] * l->y[next] - l->y[i] * l->x[next];
        }
        l->area = 0.5 * abs(area);
        counter++;
        l = l->next;
    }
}

void print_shapes(shape *l, float *arr)
{
    while (l != NULL) 
    {
        printf("Shape %d:\n", l->n);
        for (int i = 0; i < 4; i++) 
        {
            printf("(%f, %f)\n", l->x[i], l->y[i]);
        }
        printf("Area: %.2f\n\n", l->area);
        arr[k] = l->area;
        k++;
        l = l->next;
    }
}

void merge_and_sort(float *merge_arr, int size)
{
   for (int i = 0; i < size - 1; i++) 
   {
        for (int j = 0; j < size - 1 - i; j++) 
        {
            if (merge_arr[j] > merge_arr[j + 1]) 
            {
                float temp = merge_arr[j];
                merge_arr[j] = merge_arr[j + 1];
                merge_arr[j + 1] = temp;
            }
        }
    }
    
}

int main()
{
    char filename1[] = "input.txt";
    char filename2[] = "input2.txt";
    shape *shapes_list = read(filename1);
    shape *shapes_list2 = read(filename2);
    
    if (shapes_list == NULL) 
    {
        return 1;
    }

    calc_areas(shapes_list);
    calc_areas(shapes_list2);
    
    float merge_list[counter];
    
    print_shapes(shapes_list,merge_list);
    print_shapes(shapes_list2,merge_list);
    
    shape *current = shapes_list;
    while (current != NULL) 
    {
        shape *next = current->next;
        free(current);
        current = next;
    }
   
    printf("%d\n",counter);

    merge_and_sort(merge_list, counter);
    for (int i = 0; i < counter; i++)
    {
        printf("%.2lf ,", merge_list[i]);
    }
    
    return 0;
}