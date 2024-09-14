#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Chuyển đổi chiều cao từ m sang cm nếu cần
double convertHeightToCm(double height) {
    if (height < 10) {  // Giả sử nếu nhập chiều cao dưới 10 thì đơn vị là mét
        height *= 100;  // Chuyển từ m sang cm
    }
    return height;  // Nếu nhập bằng cm thì không cần chuyển đổi
}

// Tính chỉ số BMI
double calculateBMI(double weight, double height) {
    return weight / ((height / 100) * (height / 100));  // Chuyển đổi chiều cao từ cm sang m để tính BMI
}

// Đánh giá chỉ số BMI dựa trên giới tính
void evaluateBMI(double bmi, char gender) {
    if (gender == 'M' || gender == 'm') {
        // Đánh giá cho nam
        if (bmi < 18.5) {
            printf("Bạn bị thiếu cân.\n");
        } else if (bmi >= 18.5 && bmi < 24.9) {
            printf("Bạn có cân nặng bình thường.\n");
        } else if (bmi >= 25 && bmi < 29.9) {
            printf("Bạn thừa cân.\n");
        } else {
            printf("Bạn béo phì.\n");
        }
    } else if (gender == 'F' || gender == 'f') {
        // Đánh giá cho nữ
        if (bmi < 18.5) {
            printf("Bạn bị thiếu cân.\n");
        } else if (bmi >= 18.5 && bmi < 24.9) {
            printf("Bạn có cân nặng bình thường.\n");
        } else if (bmi >= 25 && bmi < 29.9) {
            printf("Bạn thừa cân.\n");
        } else {
            printf("Bạn béo phì.\n");
        }
    } else {
        printf("Giới tính không hợp lệ.\n");
    }
}

// Chuyển đổi thời gian từ 12h AM/PM sang 24h
void convertTo24HourFormat(char *timeInput, char *convertedTime) {
    int hour, minute;
    char period[3];

    sscanf(timeInput, "%d:%d %s", &hour, &minute, period);

    if (strcmp(period, "PM") == 0 && hour != 12) {
        hour += 12;
    } else if (strcmp(period, "AM") == 0 && hour == 12) {
        hour = 0;
    }

    sprintf(convertedTime, "%02d:%02d", hour, minute);
}

// Gợi ý bài tập dựa trên các vùng mục tiêu
void suggestExercises(char selectedAreas[][100], int areasCount, char exercises[][200]) {
    for (int i = 0; i < areasCount; i++) {
        if (strcmp(selectedAreas[i], "bung") == 0) {
            strcpy(exercises[i], "Plank, gập bụng, nâng chân");
        } else if (strcmp(selectedAreas[i], "chan") == 0) {
            strcpy(exercises[i], "Squat, chùng chân, nâng bắp chân");
        } else if (strcmp(selectedAreas[i], "vai") == 0) {
            strcpy(exercises[i], "Đẩy tạ đôi qua vai, đứng 2 tay dang tạ đôi, nâng tạ đôi từng tay một");
        } else if (strcmp(selectedAreas[i], "tay") == 0) {
            strcpy(exercises[i], "Chống đẩy, gập bắp tay, gập cơ tam đầu");
        } else if (strcmp(selectedAreas[i], "dui") == 0) {
            strcpy(exercises[i], "Đạp đùi, uốn cong gân kheo, căng cơ tứ đầu");
        } else if (strcmp(selectedAreas[i], "co") == 0) {
            strcpy(exercises[i], "Xoay cổ, gập và duỗi cổ, nhún vai");
        } else if (strcmp(selectedAreas[i], "body") == 0) {
            strcpy(exercises[i], "Burpees, Deadlifts, Pull-ups");
        } else {
            strcpy(exercises[i], "Không có bài tập gợi ý cho bộ phận này.");
        }
    }
}

// Lưu thông tin người dùng và thiết lập nhắc nhở
void saveAndRemind(char *name, int age, double weight, double targetWeight, double bmi, char selectedAreas[][100], int areasCount, char *convertedTime) {
    printf("\nThông tin của bạn đã được lưu lại!\n");
    printf("Tên: %s\n", name);
    printf("Tuổi: %d\n", age);
    printf("Cân nặng hiện tại: %.2f kg\n", weight);
    printf("Mục tiêu cân nặng: %.2f kg\n", targetWeight);
    printf("Chỉ số BMI: %.2f\n", bmi);

    printf("Các vùng bạn muốn tập trung giảm cân:\n");
    for (int i = 0; i < areasCount; i++) {
        printf("- %s\n", selectedAreas[i]);
    }

    printf("Thời gian nhắc nhở: %s\n", convertedTime);
}

// Hiển thị menu các vùng mục tiêu
void displayTargetAreaMenu() {
    printf("\nChọn các bộ phận bạn muốn giảm cân (nhập các số tương ứng, cách nhau bằng dấu phẩy):\n");
    printf("1. Bung\n");
    printf("2. Chan\n");
    printf("3. Vai\n");
    printf("4. Tay\n");
    printf("5. Dui\n");
    printf("6. Co\n");
    printf("7. Toàn thân\n");
}

int main() {
    printf("============================================\n");
    printf("Chào mừng bạn đến với ứng dụng theo dõi sức khỏe!\n");
    printf("Ứng dụng này giúp bạn theo dõi BMI và gợi ý bài tập phù hợp theo từng bộ phận cho bạn.\n");
    printf("Hãy làm theo quy trình nhé.\n");
    printf("============================================\n\n");

    char name[100], gender;
    int age;
    double weight, targetWeight, height, bmi;
    char preferredTime[100], convertedTime[10];

    // Nhập tên
    printf("Nhập tên của bạn: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;  // Xóa ký tự newline

    // Nhập tuổi
    printf("Nhập tuổi của bạn: ");
    scanf("%d", &age);

    // Nhập giới tính
    printf("Nhập giới tính của bạn (M/F): ");
    getchar();  // Xóa ký tự newline từ buffer trước khi nhập ký tự
    scanf("%c", &gender);

    // Nhập cân nặng
    printf("Nhập cân nặng của bạn (kg): ");
    scanf("%lf", &weight);

    // Nhập mục tiêu cân nặng
    printf("Nhập mục tiêu cân nặng của bạn (kg): ");
    scanf("%lf", &targetWeight);

    // Nhập chiều cao
    printf("Nhập chiều cao của bạn (cm hoặc m): ");
    scanf("%lf", &height);
    height = convertHeightToCm(height);  // Chuyển đổi sang cm nếu nhập bằng mét

    // Tính toán BMI
    bmi = calculateBMI(weight, height);
    printf("Chỉ số BMI của bạn là: %.2f\n", bmi);
    evaluateBMI(bmi, gender);  // Đánh giá chỉ số BMI dựa trên giới tính

    getchar();  // Xóa ký tự newline từ buffer

    displayTargetAreaMenu();

    // Nhập các vùng mục tiêu
    char targetAreasInput[100];
    printf("Nhập các lựa chọn của bạn (ví dụ: 1,3,5): ");
    fgets(targetAreasInput, sizeof(targetAreasInput), stdin);

    char areas[7][100] = {"bung", "chan", "vai", "tay", "dui", "co", "body"};
    char selectedAreas[10][100];
    int areasCount = 0;

    // Tách các lựa chọn bằng dấu phẩy
    char *token = strtok(targetAreasInput, ",");
    while (token != NULL) {
        int index = atoi(token) - 1;
        if (index >= 0 && index < 7) {
            strcpy(selectedAreas[areasCount], areas[index]);
            areasCount++;
        }
        token = strtok(NULL, ",");
    }

    // Nhập thời gian nhắc nhở
    printf("Nhập thời gian nhắc nhở (VD: 07:30 AM hoặc 19:30): ");
    fgets(preferredTime, sizeof(preferredTime), stdin);
    preferredTime[strcspn(preferredTime, "\n")] = 0;  // Xóa ký tự newline

    // Chuyển đổi thời gian sang dạng 24 giờ
    if (strstr(preferredTime, "AM") != NULL || strstr(preferredTime, "PM") != NULL) {
        convertTo24HourFormat(preferredTime, convertedTime);
    } else {
        strcpy(convertedTime, preferredTime);  // Nếu đã là 24 giờ thì không cần chuyển đổi
    }

    // Gợi ý bài tập
    char exercises[10][200];
    suggestExercises(selectedAreas, areasCount, exercises);

    // Hiển thị gợi ý bài tập
    printf("\nGợi ý bài tập cho bạn:\n");
    for (int i = 0; i < areasCount; i++) {
        printf("%s: %s\n", selectedAreas[i], exercises[i]);
    }

    // Lưu thông tin và thiết lập nhắc nhở
    saveAndRemind(name, age, weight, targetWeight, bmi, selectedAreas, areasCount, convertedTime);

    return 0;
}
