#define BUTTON_OFF 0
#define BUTTON_1 1
#define BUTTON_2 2
#define BUTTON_3 3
#define BUTTON_4 4
#define BUTTON_5 5

void update_button();
int get_button();
extern int button_value;
extern int button_pressed;
extern int last_button;