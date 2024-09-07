#include <stdio.h>
#include <string.h>

// Hàm chuyển đổi chiều cao sang mét
double convertHeightToMeters(double height) {
    if (height >= 30.0 && height <= 300.0) {
        printf("Đơn vị nhận diện: cm\n");
        return height / 100.0;  // cm sang mét
    } else if (height > 3.0 && height <= 10.0) {
        printf("Đơn vị nhận diện: feet\n");
        return height * 0.3048;  // feet sang mét
    } else {
        printf("Đơn vị nhận diện: mét\n");
        return height;  // đã là mét
    }
}

// Hàm chuyển đổi cân nặng sang kilogram
double convertWeightToKg(double weight) {
    if (weight > 100.0) {
        printf("Đơn vị nhận diện: pound\n");
        return weight * 0.453592;  // pound sang kilogram
    } else {
        printf("Đơn vị nhận diện: kilogram\n");
        return weight;  // đã là kilogram
    }
}

double calculateBMI(double weight, double height) {
    return weight / (height * height);
}

// Hàm đánh giá mức độ BMI
void evaluateBMI(double bmi) {
    if (bmi < 18.5) {
        printf("Bạn thuộc nhóm: Thiếu cân\n");
    } else if (bmi >= 18.5 && bmi < 25.0) {
        printf("Bạn thuộc nhóm: Bình thường (Cân nặng khỏe mạnh)\n");
    } else if (bmi >= 25.0 && bmi < 30.0) {
        printf("Bạn thuộc nhóm: Thừa cân\n");
    } else if (bmi >= 30.0 && bmi < 35.0) {
        printf("Bạn thuộc nhóm: Béo phì độ 1\n");
    } else if (bmi >= 35.0 && bmi < 40.0) {
        printf("Bạn thuộc nhóm: Béo phì độ 2\n");
    } else {
        printf("Bạn thuộc nhóm: Béo phì độ 3 (Nguy hiểm)\n");
    }
}

void suggestExercises(char areas[][100], int areasCount, char exercises[][200]) {
    int i = 0;
    for (int j = 0; j < areasCount; j++) {
        if (areas[j][0] == 'b' && areas[j][1] == 'u') {
            sprintf(exercises[i++], "Plank, gập bụng, nâng chân");
        } else if (areas[j][0] == 'c' && areas[j][1] == 'h') {
            sprintf(exercises[i++], "Squat, chùng chân, nâng bắp chân");
        } else if (areas[j][0] == 'v' && areas[j][1] == 'a') {
            sprintf(exercises[i++], "Đẩy tạ đôi qua vai, đứng 2 tay dang tạ đôi, nâng tạ đôi từng tay một");
        } else if (areas[j][0] == 't' && areas[j][1] == 'a') {
            sprintf(exercises[i++], "Chống đẩy, gập bắp tay, gập cơ tam đầu");
        } else if (areas[j][0] == 'd' && areas[j][1] == 'u') {
            sprintf(exercises[i++], "Đạp đùi, uốn cong gân kheo, căng cơ tứ đầu");
        } else if (areas[j][0] == 'c' && areas[j][1] == 'o') {
            sprintf(exercises[i++], "Xoay cổ, gập và duỗi cổ, nhún vai");
        } else if (areas[j][0] == 'b' && areas[j][1] == 'o') {
            sprintf(exercises[i++], "Burpees, Deadlifts, Pull-ups");
        } else {
            sprintf(exercises[i++], "Không có bài tập gợi ý cho bộ phận %s", areas[j]);
        }
    }
}

void saveAndRemind(char *name, int age, double weight, double targetWeight, double bmi, char areas[][100], int areasCount, char *preferredTime) {
    printf("Thông tin đã được lưu lại.\n");
    printf("Chỉ số BMI của bạn là: %.2f\n", bmi);
    evaluateBMI(bmi);  // Đánh giá BMI
    printf("Nhắc nhở được thiết lập vào %s.\n", preferredTime);
}

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
    char name[100];
    int age;
    double weight, targetWeight, height, bmi;
    char preferredTime[100];
    
    // Nhập tên
    printf("Nhập tên của bạn: ");
    fgets(name, sizeof(name), stdin);
    for (int i = 0; name[i] != '\0'; i++) {  // Xóa newline
        if (name[i] == '\n') name[i] = '\0';
    }

    // Nhập tuổi
    printf("Nhập tuổi của bạn: ");
    scanf("%d", &age);

    // Nhập cân nặng
    printf("Nhập cân nặng của bạn: ");
    scanf("%lf", &weight);
    weight = convertWeightToKg(weight);

    // Nhập mục tiêu cân nặng
    printf("Nhập mục tiêu cân nặng của bạn (kg): ");
    scanf("%lf", &targetWeight);

    // Nhập chiều cao
    printf("Nhập chiều cao của bạn: ");
    scanf("%lf", &height);
    height = convertHeightToMeters(height);

    // Tính toán BMI
    bmi = calculateBMI(weight, height);
    printf("Chỉ số BMI của bạn là: %.2f\n", bmi);
    evaluateBMI(bmi);  // Đánh giá chỉ số BMI

    getchar();  // clear newline from buffer
    displayTargetAreaMenu();

    // Nhập các vùng mục tiêu
    char targetAreasInput[100];
    printf("Nhập các lựa chọn của bạn (ví dụ: 1,3,5): ");
    fgets(targetAreasInput, sizeof(targetAreasInput), stdin);

    char areas[7][100] = {"bung", "chan", "vai", "tay", "dui", "co", "body"};
    char selectedAreas[10][100];
    int areasCount = 0;

    // Tách các lựa chọn bằng dấu phẩy
    for (int i = 0; targetAreasInput[i] != '\0'; i++) {
        if (targetAreasInput[i] >= '1' && targetAreasInput[i] <= '7') {
            int index = targetAreasInput[i] - '1';
            for (int k = 0; areas[index][k] != '\0'; k++) {
                selectedAreas[areasCount][k] = areas[index][k];
            }
            areasCount++;
        }
    }

    // Nhập thời gian nhắc nhở
    printf("Nhập thời gian trong ngày mà bạn muốn nhắc nhở: ");
    fgets(preferredTime, sizeof(preferredTime), stdin);
    for (int i = 0; preferredTime[i] != '\0'; i++) {  // Xóa newline
        if (preferredTime[i] == '\n') preferredTime[i] = '\0';
    }

    // Gợi ý bài tập
    char exercises[10][200];
    suggestExercises(selectedAreas, areasCount, exercises);

    printf("\nGợi ý bài tập cho bạn:\n");
    for (int i = 0; i < areasCount; i++) {
        printf("%s: %s\n", selectedAreas[i], exercises[i]);
    }

    // Lưu thông tin và nhắc nhở
    saveAndRemind(name, age, weight, targetWeight, bmi, selectedAreas, areasCount, preferredTime);

    return 0;
}
