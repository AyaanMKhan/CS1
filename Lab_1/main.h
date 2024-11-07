struct Student {
    int student_id;
    int g1, g2, g3;
    float average;
};

void readData(struct Student *students, int *c);

struct Student getMaxAverageStudent(struct Student *s, int n);

