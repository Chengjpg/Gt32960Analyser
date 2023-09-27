#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

//car_init
#define CAR_LOGIN           0x01
#define REAL_INFORMATION    0x02
#define SUPP_INFORMATION    0x03
#define CAR_LOGOUT          0x04
#define PLAT_LOGIN          0x05
#define PLAT_LOGOUT         0x06


#define REAL_WHOLE_CAR           0x01
#define REAL_DRIVE_MOTOR         0x02
#define REAL_FUEL_BATTERY        0x03
#define REAL_ENGINE              0x04
#define REAL_POS                 0x05
#define REAL_MAXI                0x06
#define REAL_WARN                0x07

//ʱ��ṹ��
struct TIME{
    uint8_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
};
struct DRIVE_MOTOR{
    uint8_t number;                 //���
    uint8_t status;                 //״̬
    uint8_t control_tempreture;     //�����¶�
    uint16_t speed;                 //���ת��
    uint16_t torsion;               //���ת��
    uint8_t tempreture;             //����¶�
    uint16_t input_voltage;         //�����ѹ
    uint16_t main_current;          //ֱ��ĸ�ߵ���
};
//�����ṹ��
struct ELECTRONIC_CAR{
    //����ͷ������
    uint8_t command_symbol;     //�����ʶ
    uint8_t respond_symbol;     //Ӧ���ʶ
    char vin[18];               //����Ψһʶ����
    uint8_t encrypt_method;     //���ܷ�ʽ
    uint16_t data_len;          //���ݳ���

    struct TIME general_time;                //ͨ��ʱ��

    //���ݵ�Ԫ
    //��������������Ϣ
    uint16_t car_login_seq;                 //������ˮ��
    char car_login_iccid[21];                            //SIM��ICCID��
    uint8_t car_login_n;
    uint8_t car_login_m;
    char* car_login_charge_system_code;        //�ɳ�索��ϵͳ����

    //ʵʱ��Ϣ�ϱ�
        //��������
        uint8_t have_whole_char;               //�Ƿ�����������
        uint8_t whole_car_car_status;          //����״̬
        uint8_t whole_car_charge_status;       //���״̬
        uint8_t whole_car_run_status;          //����״̬
        uint16_t whole_car_speed;              //����
        uint32_t whole_car_distance;           //�ۼ����
        uint16_t whole_car_voltage;            //��ѹ
        uint16_t whole_car_current;            //����
        uint8_t whole_car_soc;                 //SOC
        uint8_t whole_car_dc_status;           //DC״̬
        uint8_t whole_car_gear;                //��λ
        uint16_t whole_car_resistance;         //��Ե����
        uint16_t whole_car_preset;             //Ԥ��

        //�����������
        uint8_t have_drive;                    //�Ƿ��������������
        uint8_t drive_quantity;                //�����������
        struct DRIVE_MOTOR* drive_motor;       //�����������

        //ȼ�ϵ������
        uint8_t have_fuel_battery;             //�Ƿ���ȼ�ϵ������
        uint16_t fuel_battery_voltage;         //ȼ�ϵ�ص�ѹ
        uint16_t fuel_battery_current;         //ȼ�ϵ�ص���
        uint16_t fuel_battery_consume_rate;    //ȼ��������
        uint16_t fuel_battery_sum_probe;       //�¶�̽������
        uint8_t* fuel_battery_probe;           //�¶�̽������
        uint16_t fuel_battery_max_tem;         //��ϵͳ������¶�
        uint8_t fuel_battery_max_tem_index;    //��ϵͳ������¶�̽�����
        uint16_t fuel_battery_max_con;          //���Ũ��
        uint8_t fuel_battery_max_con_index;    //���Ũ�ȴ���������
        uint16_t fuel_battery_max_pre;         //���ѹ��
        uint8_t fuel_battery_max_pre_index;    //���ѹ������������
        uint8_t fuel_battery_dc_status;        //DC״̬

        //����������
        uint8_t have_engine;                   //�Ƿ��з���������
        uint8_t engine_status;                 //������״̬
        uint16_t engine_speed;                 //����ת��
        uint16_t engine_fuel_consume_rate;     //ȼ��������

        //����λ������
        uint8_t have_pos;                      //�Ƿ��ж�λ����
        uint8_t pos_status;                    //��λ״̬
        uint32_t pos_longitude;                //����
        uint32_t pos_latitude;                 //γ��

        //��ֵ����
        uint8_t have_maxi;                     //�Ƿ��м�ֵ����
        uint8_t max_vol_bat_sys_index;         //��ߵ�ѹ�����ϵͳ��
        uint8_t max_vol_bat_ini_index;         //��ߵ�ѹ��ص������
        uint16_t bat_ini_max_vol;              //��������ߵ�ѹ
        uint8_t min_vol_bat_sys_index;         //��͵�ѹ�����ϵͳ��
        uint8_t min_vol_bat_ini_index;         //��͵�ѹ��ص������
        uint16_t bat_ini_min_vol;              //��������͵�ѹ
        uint8_t max_tem_sys_index;             //����¶���ϵͳ��
        uint8_t max_tem_probe_index;           //����¶�̽�����
        uint8_t max_tem;                       //����¶�ֵ
        uint8_t min_tem_sys_index;             //����¶���ϵͳ��
        uint8_t min_tem_probe_index;           //����¶�̽�����
        uint8_t min_tem;                       //����¶�ֵ

        //��������
        uint8_t have_warn;                     //�Ƿ��б�������
        uint8_t warn_max_level;                //��߱����ȼ�
        uint32_t warn_general_mark;            //ͨ�ñ�����־
        uint8_t warn_charge_app_number;        //�ɳ�索��װ�ù�������
        uint32_t* warn_charge_app;             //�ɳ�索��װ�ù����б�
        uint8_t warn_drive_motor_number;        //���������������
        uint32_t* warn_drive_motor_app;             //������������б�
        uint8_t warn_engine_number;        //�����������
        uint32_t* warn_engine_app;             //��������б�
        uint8_t warn_other_number;        //������������
        uint32_t* warn_other_app;             //���������б�


    //�����ǳ�
    uint16_t car_logout_seq;                   //�ǳ���ˮ��

    //ƽ̨����
    uint16_t plat_login_seq;                   //ƽ̨������ˮ��
    char plat_login_username[13];                        //ƽ̨�û���
    char plat_login_password[21];                    //ƽ̨����
    uint8_t plat_login_encrypt_rule;           //���ܹ���

    //ƽ̨�ǳ�
    uint16_t plat_logout_seq;                  //ƽ̨�ǳ���ˮ��

    //����β������
    uint8_t check_byte;         //У����
};
struct myobject
{
        struct ELECTRONIC_CAR* ec;
};


void parse_time(struct ELECTRONIC_CAR* ec, uint16_t data_len, uint8_t* data){
    int index = 0;
    ec->general_time.year = data[index++];
    printf("0x%02X\n",ec->general_time.year);
    ec->general_time.month = data[index++];
    ec->general_time.day = data[index++];
    ec->general_time.hour = data[index++];
    ec->general_time.minute = data[index++];
    ec->general_time.second = data[index++];
    return;
}

int car_login_parse(struct ELECTRONIC_CAR* ec, uint16_t data_len, uint8_t* data){
    if(data_len < 30){
        printf("car login information length is not enough.\n");
        return 0;
    }
    parse_time(ec, data_len, data);

    int index = 6;
    ec->car_login_seq = 256*data[index] + data[index+1];
    index += 2;
    memcpy(ec->car_login_iccid, &data[index], 20);
    ec->car_login_iccid[20] = '\0';
    index += 20;
    ec->car_login_n = data[index++];
    ec->car_login_m = data[index++];
    uint32_t sys_len = ec->car_login_n*ec->car_login_m;
    if(30+sys_len < data_len){
        printf("car login information mn length is not enough.\n");
        return 0;
    }
    ec->car_login_charge_system_code = (uint8_t*)malloc(sys_len+1);
    memcpy(ec->car_login_charge_system_code, &data[index], sys_len);
    ec->car_login_charge_system_code[sys_len] = '\0';
    return 1;
}


int real_information_whole_car_parse(struct ELECTRONIC_CAR* ec, uint16_t data_len, uint8_t* data, int* index){
    if(data_len < *index+20){
        printf("real information whole car length is not enough.\n");
        return 0;
    }
    ec->whole_car_car_status = data[*index];
    *index = *index+1;
    ec->whole_car_charge_status = data[*index];
    *index = *index+1;
    ec->whole_car_run_status = data[*index];
    *index = *index+1;
    ec->whole_car_speed = 256*data[*index] + data[*index+1];
    *index = *index+2;
    ec->whole_car_distance = 256*256*256*data[*index] + 256*256*data[*index+1] + 256*data[*index+2] + data[*index+3];
    *index = *index+4;
    ec->whole_car_voltage = 256*data[*index] + data[*index+1];
    *index = *index+2;
    ec->whole_car_current = 256*data[*index] + data[*index+1];
    *index = *index+2;
    ec->whole_car_soc = data[*index];
    *index = *index+1;
    ec->whole_car_dc_status = data[*index];
    *index = *index+1;
    ec->whole_car_gear = data[*index];
    *index = *index+1;
    ec->whole_car_resistance = 256*data[*index] + data[*index+1];
    *index = *index+2;
    ec->whole_car_preset = 256*data[*index] + data[*index+1];
    *index = *index+2;
    ec->have_whole_char = 1;
    return 1;
}

int real_information_drive_motor_parse(struct ELECTRONIC_CAR* ec, uint16_t data_len, uint8_t* data, int* index){
    if(data_len < *index+1){
        printf("real information drive motor length is not enough.\n");
        return 0;
    }
    ec->drive_quantity = data[*index];
    *index = *index+1;
    if(data_len < *index+ec->drive_quantity*12){
        printf("real information drive motor list length is not enough.\n");
        return 0;
    }

    ec->drive_motor = (struct DRIVE_MOTOR*)malloc(ec->drive_quantity* (sizeof(struct DRIVE_MOTOR)));
    for(int i = 0; i < ec->drive_quantity; i++){
        struct DRIVE_MOTOR* cur = &(ec->drive_motor[i]);
        cur->number = data[*index];
        *index = *index+1;
        cur->status = data[*index];
        *index = *index+1;
        cur->control_tempreture = data[*index];
        *index = *index+1;
        cur->speed = 256*data[*index] + data[*index+1];
        *index = *index+2;
        cur->torsion = 256*data[*index] + data[*index+1];
        *index = *index+2;
        cur->tempreture = data[*index];
        *index = *index+1;
        cur->input_voltage = 256*data[*index] + data[*index+1];
        *index = *index+2;
        cur->main_current = 256*data[*index] + data[*index+1];
        *index = *index+2;
    }
    ec->have_drive = 1;
    return 1;
}

int real_information_fuel_battery_parse(struct ELECTRONIC_CAR* ec, uint16_t data_len, uint8_t* data, int* index){
    if(data_len < *index+8){
        printf("real information fuel battery length not enough.\n");
        return 0;
    }
    ec->fuel_battery_voltage = 256*data[*index] + data[*index+1];
    *index = *index+2;
    ec->fuel_battery_current = 256*data[*index] + data[*index+1];
    *index = *index+2;
    ec->fuel_battery_consume_rate = 256*data[*index] + data[*index+1];
    *index = *index+2;
    ec->fuel_battery_sum_probe = 256*data[*index] + data[*index+1];
    *index = *index+2;

    if(data_len < *index+ec->fuel_battery_sum_probe+10){
        printf("real information fuel battery after length not enough.\n");
        return 0;
    }
    ec->fuel_battery_probe = (uint8_t*)malloc(ec->fuel_battery_sum_probe);
    for(int i = 0; i < ec->fuel_battery_sum_probe; i++){
        ec->fuel_battery_probe[i] = data[*index];
        *index = *index+1;
    }

    ec->fuel_battery_max_tem = 256*data[*index] + data[*index+1];
    *index = *index+2;
    ec->fuel_battery_max_tem_index = data[*index];
    *index = *index+1;
    ec->fuel_battery_max_con = 256*data[*index] + data[*index+1];
    *index = *index+2;
    ec->fuel_battery_max_con_index = data[*index];
    *index = *index+1;
    ec->fuel_battery_max_pre = 256*data[*index] + data[*index+1];
    *index = *index+2;
    ec->fuel_battery_max_pre_index = data[*index];
    *index = *index+1;
    ec->fuel_battery_dc_status = data[*index];
    *index = *index+1;
    ec->have_fuel_battery = 1;
    return 1;
}

int real_information_engine_parse(struct ELECTRONIC_CAR* ec, uint16_t data_len, uint8_t* data, int* index){
    if(data_len < *index+5){
        printf("real information engine length is not enough.\n");
        return 0;
    }
    ec->engine_status = data[*index];
    *index = *index+1;
    ec->engine_speed = 256*data[*index] + data[*index+1];
    *index = *index+2;
    ec->engine_fuel_consume_rate = 256*data[*index] + data[*index+1];
    *index = *index+2;
    ec->have_engine = 1;
    return 1;
}

int real_information_pos_parse(struct ELECTRONIC_CAR* ec, uint16_t data_len, uint8_t* data, int* index){
    if(data_len < *index+9){
        printf("real information pos length is not enough.\n");
        return 0;
    }
    ec->pos_status = data[*index];
    *index = *index+1;
    ec->pos_longitude = 256*256*256*data[*index] + 256*256*data[*index+1] + 256*data[*index+2] + data[*index+3];
    *index = *index+4;
    ec->pos_latitude = 256*256*256*data[*index] + 256*256*data[*index+1] + 256*data[*index+2] + data[*index+3];
    *index = *index+4;
    ec->have_pos = 1;
    return 1;
}

int real_information_maxi_parse(struct ELECTRONIC_CAR* ec, uint16_t data_len, uint8_t* data, int* index){
    if(data_len < *index+14){
        printf("real information maxi length is not enough.\n");
        return 0;
    }
    ec->max_vol_bat_sys_index = data[*index];
    *index = *index+1;
    ec->max_vol_bat_ini_index = data[*index];
    *index = *index+1;
    ec->bat_ini_max_vol = 256*data[*index] + data[*index+1];
    *index = *index+2;
    ec->min_vol_bat_sys_index = data[*index];
    *index = *index+1;
    ec->min_vol_bat_ini_index = data[*index];
    *index = *index+1;
    ec->bat_ini_min_vol = 256*data[*index] + data[*index+1];
    *index = *index+2;
    ec->max_tem_sys_index = data[*index];
    *index = *index+1;
    ec->max_tem_probe_index = data[*index];
    *index = *index+1;
    ec->max_tem = data[*index];
    *index = *index+1;
    ec->min_tem_sys_index = data[*index];
    *index = *index+1;
    ec->min_tem_probe_index = data[*index];
    *index = *index+1;
    ec->min_tem = data[*index];
    *index = *index+1;

    ec->have_maxi = 1;
    return 1;
}


int real_information_warn_parse(struct ELECTRONIC_CAR* ec, uint16_t data_len, uint8_t* data, int* index){
    if(data_len < *index+6){
        printf("real information warn length is not enough.\n");
        return 0;
    }

    ec->warn_max_level = data[*index];
    *index = *index+1;
    ec->warn_general_mark = 256*256*256*data[*index] + 256*256*data[*index+1] + 256*data[*index+2] + data[*index+3];
    *index = *index+4;

    //�ɳ�索��
    ec->warn_charge_app_number = data[*index];
    *index = *index+1;
    if(data_len < *index+4*ec->warn_charge_app_number+1){
        printf("real information warn charge length is not enough.\n");
        return 0;
    }
    ec->warn_charge_app = (uint32_t*)malloc(4*ec->warn_charge_app_number);
    for(int i = 0; i < ec->warn_charge_app_number; i++){
        ec->warn_charge_app[i] = 256*256*256*data[*index] + 256*256*data[*index+1] + 256*data[*index+2] + data[*index+3];
        *index = *index+4;
    }

    //�������
    ec->warn_drive_motor_number = data[*index];
    *index = *index+1;
    if(data_len < *index+4*ec->warn_drive_motor_number+1){
        printf("real information warn charge length is not enough.\n");
        //free(ec->warn_charge_app);
        ec->warn_charge_app_number = 0;
        return 0;
    }
    ec->warn_drive_motor_app = (uint32_t*)malloc(4*ec->warn_drive_motor_number);
    for(int i = 0; i < ec->warn_drive_motor_number; i++){
        ec->warn_drive_motor_app[i] = 256*256*256*data[*index] + 256*256*data[*index+1] + 256*data[*index+2] + data[*index+3];
        *index = *index+4;
    }

    //������
    ec->warn_engine_number = data[*index];
    *index = *index+1;
    if(data_len < *index+4*ec->warn_engine_number+1){
        printf("real information warn charge length is not enough.\n");
        //free(ec->warn_charge_app);
        ec->warn_charge_app_number = 0;

        //free(ec->warn_drive_motor_app);
        ec->warn_drive_motor_number = 0;
        return 0;
    }
    ec->warn_engine_app = (uint32_t*)malloc(4*ec->warn_engine_number);
    for(int i = 0; i < ec->warn_engine_number; i++){
        ec->warn_engine_app[i] = 256*256*256*data[*index] + 256*256*data[*index+1] + 256*data[*index+2] + data[*index+3];
        *index = *index+4;
    }

    //��������
    ec->warn_other_number = data[*index];
    *index = *index+1;
    if(data_len < *index+4*ec->warn_other_number){
        printf("real information warn charge length is not enough.\n");
        //free(ec->warn_charge_app);
        ec->warn_charge_app_number = 0;

        //free(ec->warn_engine_app);
        ec->warn_engine_number = 0;

        //free(ec->warn_drive_motor_app);
        ec->warn_drive_motor_number = 0;
        return 0;
    }
    ec->warn_other_app = (uint32_t*)malloc(4*ec->warn_other_number);
    for(int i = 0; i < ec->warn_other_number; i++){
        ec->warn_other_app[i] = 256*256*256*data[*index] + 256*256*data[*index+1] + 256*data[*index+2] + data[*index+3];
        *index = *index+4;
    }

    ec->have_warn = 1;
}

int real_information_parse(struct ELECTRONIC_CAR* ec, uint16_t data_len, uint8_t* data){
    if(data_len < 6){
        printf("real information time length not enough.\n");
        return 0;
    }
    parse_time(ec, data_len, data);

    int index = 6;
    while(index < data_len-1){
        int type = data[index++];
        if(type == REAL_WHOLE_CAR){
            if(!real_information_whole_car_parse(ec, data_len, data, &index)){
                return 0;
            }
            continue;
        }else if(type == REAL_DRIVE_MOTOR){
            if(!real_information_drive_motor_parse(ec, data_len, data, &index)){
                return 0;
            }
            continue;
        }else if(type == REAL_FUEL_BATTERY){
            if(!real_information_fuel_battery_parse(ec, data_len, data, &index)){
                return 0;
            }
            continue;
        }else if(type == REAL_ENGINE){
            if(!real_information_engine_parse(ec, data_len, data, &index)){
                return 0;
            }
            continue;
        }else if(type == REAL_POS){
            if(!real_information_pos_parse(ec, data_len, data, &index)){
                return 0;
            }
            continue;
        }else if(type == REAL_MAXI){
            if(!real_information_maxi_parse(ec, data_len, data, &index)){
                return 0;
            }
            continue;
        }else if(type == REAL_WARN){
            if(!real_information_warn_parse(ec, data_len, data, &index)){
                return 0;
            }
            continue;
        }else{
            printf("Unable to process the reserved fields\n");
            return 1;
        }
    }

    return 1;
}


int car_logout_parse(struct ELECTRONIC_CAR* ec, uint16_t data_len, uint8_t* data){
    if(data_len < 8){
        printf("car logout length is not enough.\n");
        return 0;
    }
    parse_time(ec, data_len, data);

    int index = 6;
    ec->car_logout_seq = 256*data[index] + data[index+1];
    index = index+2;
    return 1;
}


int plat_login_parse(struct ELECTRONIC_CAR* ec, uint16_t data_len, uint8_t* data){
    if(data_len < 41){
        printf("plat login length is not enough.\n");
        return 0;
    }
    parse_time(ec, data_len, data);

    int index = 6;
    ec->plat_login_seq = 256*data[index] + data[index+1];
    index = index+2;
    memcpy(ec->plat_login_username, &data[index], 12);
    ec->plat_login_username[12] = '\0';
    index = index+12;
    memcpy(ec->plat_login_password, &data[index], 20);
    ec->plat_login_password[20] = '\0';
    index = index+20;
    ec->plat_login_encrypt_rule = data[index];
    index = index+1;
    return 1;
}


int plat_logout_parse(struct ELECTRONIC_CAR* ec, uint16_t data_len, uint8_t* data){
    if(data_len < 8){
        printf("plat logout length is not enough.\n");
        return 0;
    }

    parse_time(ec, data_len, data);

    int index = 6;
    ec->plat_logout_seq = 256*data[index] + data[index+1];
    index = index+2;
    return 1;
}

//����ǰ24�ֽڵĽ���
int header_parse(struct myobject* t, uint8_t* data){
    if(data[0] != 0x23 || data[1] != 0x23){
        return 0;
    }

    int index = 2;
    t->ec->command_symbol = data[index++];
    t->ec->respond_symbol = data[index++];
    memcpy(t->ec->vin, &data[index], 17);  //vin�ĳ���Ϊ17
    index += 17;
    t->ec->vin[17]='\0';
    t->ec->encrypt_method = data[index++];
    t->ec->data_len = 256*data[index] + data[index+1];
    index += 2;
    return 1;
}

//���ݰ���Ľ���
int body_parse(struct ELECTRONIC_CAR* ec, uint16_t data_len, uint8_t* data){
    switch(ec->command_symbol){
        case CAR_LOGIN:{
            return car_login_parse(ec, data_len, data);
        }
        case REAL_INFORMATION:{
            return real_information_parse(ec, data_len, data);
        }
        case SUPP_INFORMATION:{
            return real_information_parse(ec, data_len, data);
        }
        case CAR_LOGOUT:{
            return car_logout_parse(ec, data_len, data);
        }
        case PLAT_LOGIN:{
            return plat_login_parse(ec, data_len, data);
        }
        case PLAT_LOGOUT:{
            return plat_logout_parse(ec, data_len, data);
        }
    }
}

char* packet="232303FE584C32434546355030414C30303730323301012D15071C110B320102030100000000010E0C58271000021013510065020101014F4E204E2055001F271005000633555501D2D2CE0601220D00011F0B1501014B010B49070300000450000000000801010C58271000600001600CBD0CD90CD00CCF0CE00CF00CE00CCB0CE10CE00CDF0CC80CC50CD30CCF0CE70CE50CE30CD90CE90CF60CEF0CE10CDF0CEA0CED0CE80CD10CDA0CEE0B150CD30CED0D000CCA0CED0CD60CDA0CED0CDC0CE70CF00CED0CDF0CF40CF30CDC0CE50CE00CEF0CE10CD20CDD0CE80CD60CEA0CDD0CE90CD90CD60CC90CCB0CDE0CCC0CD30CD60CE60CF20CE20CCC0CE90CE40CF80CA00CE50CE10CE90CE80CE20CF70CF50CEA0CCD0CF80CE50CDD0CE00CE10CE90CDD0CEB0CEE0CF40CF60CFC0CE109010100104B4A4A4A4949494A4A49494A4A4A4A4A5F";
//char* packet="2323068568B4770875BCCF5A8B1FFCA3AA463AA923A83DF4647CF6BE410205443173EE006C372F511533AB1F67CF60B275F338F64D220104C875E85ABB6B90C5FCC7D98B9D26CD6F7E5395C6325B320AE3148529B4BCC6F509427BB856896AE3B1706C87F4335B75105807E0BC5823419A9A6E0E448917647915673C5E61A2E5CBA605D1869B94DC2975498F276BE1C6EF2FD684B341D28F8FE9E861A6870149930212911FF3443616FF254F6A3F9D8F8C8A08E768B2133BD983030D1D6EE259A7D70D32F1423D198AB42173373FF957034928CDDB86ADFFC866D302B52F0470876FCAC55933D54F46579064C8C2373C99E28EACA97E616FDBAD45133BA05F52054BECE1B3E2B93F4323DAC73C3B3F353C9086B47D78778E2FF329BBCA7CF8B03BFC77579DBD01ED4E2CF97EE9D4643FE353EE48F42852C46BB929447EBEBB3C29D46E3514396B50F1ECE59125A91189018B3ACA584FA2C741DA1C61DDA2713F5F9AD7714948F2D7E30CEEBB357DD923D340D410CDF5C6032DB3F6F731AB16C1119FD5E1EC2153034CB4E4B3902A3D32A27775B40858732AE2C4FC0BDC9753E33E8CAB8B0EBCA9C4CE00E8A0193FDFBB2EA561EB7E4D83520EA9466472023454D7EF0BFE2EAAD24582FC4F716976ADA90C733D3B4E5385BF6B65FE334F07102158EBF4B9AEB22B24CDC4A3A55478A40388062A2802BE80479E7F9F623009784A98B8462E4044EEDE80284B0BD3046602BF2272A2DE041963B837E1AB6837BCA8277816B279791628E6FD28C6886F0C6824923399515A72B20544E07955EA82CC59CB1BACA9148375524A828D054CE1C817169F7D292B3CDEB772AEB9E0522A94EB32167B40D9BE8A4353E3F4DBDAB86D32EAFAE70A9D76A816243CD5CB48BBD8B91959DF592EAB117A403E6E747A911896310C715FF1E29E191B899EE8E573D83CCCAE1B832B7D7939A6855FE78E6A9978245703D977AF9873776368B0FF2503264A9939FE8F245C88A8271509C4DD6A72242D2A306D33253EB121039E03FAEB7B98C02CE3C6DCD64D8BC4A59C0A815B8B371A2028B173CED40AECE4B6DC5083402BAE7361B18E690FDF83FB55D93E9E7F2F6E5C1E94C7B65F30661388E277F7413BFC0CA6D9BF5A05EAD56E398442EBC95A2E8DB77AA7EAEC0741AF2CFE2E375EEC350A54368C258E1D32347843251E78267DA1A68EC34E93FA3CE4B28EBAB97D4B6D4192A69AE2D82C5BD2D5BBABEF1586E90B4F211603AD99A2023056F0E7424B7D82EA50228D004D588B20612ADED108AE74860E6E715A61A4F77E0D502A47C1B803540586EF7B0CECAC0F84B3355B1DAF97D6B61E95443B38DABB338DD222A1B750F0624E2D07F61BD53566A74F4A048C066D49F5508F4A9C29D804B8B2F18B07DE932C015F4E78E6DC9C12CD6834BF0425B10C882663F5D3B5861623589024464749C27F09CFF7B3D40FF02B8DFFC1E1DB852B5DD281EEB1A459844D3C958C5C752E785B4DD4F110362E9B69A10F974C91E24CE58890D8B6E4808E6BE72430CF845B2F13B827CEB3A782AC34DF70CADFCD555BDF7362F15FD67F54F311E20860FC76B3A911C7F3C685C96DC955BF9455B15555EC54888E199C3B9FFED247485D3879D69EBE9A391F13DC1F9E261498EBDA9D122424F0AB5CE4F564E94D75337397D24D9B0819EC68053A2ACE7FAC1B9843EA751EF32649B0635F1845BA64202092D334E798BD0EA7CF178AB0D11FEE8EE7FBF3C7EAEDE9E9E2E7E3E3CEE74188EB4561AFE9331AF8AA4187B0ADF461CF6C690EFE17E89693B3F695BBDFDC2E39DBECFDE41636F67EB2B531B0BD5B4A5104B5C3C7BF9C075DC7FAF256F6B78F54BEE67B5F9BFD7C0FA3F73D51EFD5586E01C29618EFF2E3CC87BA304C1C8C68774B1F4013467489A4C499C9A0694B2E2026432F12BFBF7114EE9559697D78A7D1EB2702A7E7442E993246697717BBB5B0F5365E00308462D757963053EB9D08C4CC4EB2230E898E22C44E9722536F26019CB34CBA5EA22836D1CA53C0D1";
int StringToBuff(char *str,unsigned char *OutputBuff)
{
	char *p = NULL;
	char High = 0;
	char Low = 0;
	int i = 0;
	int Len = 0;
	int count = 0;

	p = str;
	Len = strlen(p);

	while(count < (Len/2))
    {
        High = ((*p > '9') && ((*p <= 'F') || (*p <= 'f')))?*p - 48 - 7 : *p - 48;
		Low = (*(++ p) > '9' && ((*p <= 'F') || (*p <= 'f')))? *p - 48 - 7 : *p - 48;
        OutputBuff[count] = ((High & 0x0f) << 4 | (Low & 0x0f));
        p ++;
        count ++;
    }
	//�ж��ַ��������Ƿ�Ϊ����
	if(0 != Len%2)
	{
		OutputBuff[count++] = ((*p >'9')&&(*p<='F')||(*p<='f'))?*p-48-7:*p-48;
	}

	return Len/2 + Len%2;
}


    void Fout_put(struct ELECTRONIC_CAR* ec){
    FILE* fp = fopen("./Electronic_Car_Feather.txt", "a+");

    fprintf(fp,"==================================================\n");
    fprintf(fp,"command_symbol: %u\n", ec->command_symbol);
    fprintf(fp,"respond_symbol: %u\n", ec->respond_symbol);
    fprintf(fp,"vin: %s\n", ec->vin);
    fprintf(fp,"encrypt_method: %u\n", ec->encrypt_method);
    fprintf(fp,"data_len: %u\n", ec->data_len);
    fprintf(fp,"general_time: %u��%u��%u��%uʱ%u��%u��\n", ec->general_time.year, ec->general_time.month ,  ec->general_time.day, ec->general_time.hour, ec->general_time.minute, ec->general_time.second);

    switch(ec->command_symbol){
        case CAR_LOGIN:{
            fprintf(fp,"car_login_seq: %u\n", ec->car_login_seq);
            fprintf(fp,"car_login_iccid: %s\n", ec->car_login_iccid);
            fprintf(fp,"car_login_n: %u\n", ec->car_login_n);
            fprintf(fp,"car_login_m: %u\n", ec->car_login_m);
            fprintf(fp,"car_login_charge_system_code: %s\n", ec->car_login_charge_system_code);
            break;
        }
        case REAL_INFORMATION:{
            if(ec->have_whole_char){
                fprintf(fp,"whole_car_car_status: %u\n", ec->whole_car_car_status);
                fprintf(fp,"whole_car_charge_status: %u\n", ec->whole_car_charge_status);
                fprintf(fp,"whole_car_run_status: %u\n", ec->whole_car_run_status);
                fprintf(fp,"whole_car_speed: %u\n", ec->whole_car_speed);
                fprintf(fp,"whole_car_distance: %u\n", ec->whole_car_distance);
                fprintf(fp,"whole_car_voltage: %u\n", ec->whole_car_voltage);
                fprintf(fp,"whole_car_current: %u\n", ec->whole_car_current);
                fprintf(fp,"whole_car_soc: %u\n", ec->whole_car_soc);
                fprintf(fp,"whole_car_dc_status: %u\n", ec->whole_car_dc_status);
                fprintf(fp,"whole_car_gear: %u\n", ec->whole_car_gear);
                fprintf(fp,"whole_car_resistance: %u\n", ec->whole_car_resistance);
                fprintf(fp,"whole_car_preset: %u\n", ec->whole_car_preset);
            }

            if(ec->have_drive){
                fprintf(fp,"drive_quantity: %u\n", ec->drive_quantity);
                for(int i = 0; i < ec->drive_quantity; i++){
                    fprintf(fp,"--------------------\n");
                    fprintf(fp,"number: %u\n", ec->drive_motor[i].number);
                    fprintf(fp,"status: %u\n", ec->drive_motor[i].status);
                    fprintf(fp,"control_tempreture: %u\n", ec->drive_motor[i].control_tempreture);
                    fprintf(fp,"speed: %u\n", ec->drive_motor[i].speed);
                    fprintf(fp,"torsion: %u\n", ec->drive_motor[i].torsion);
                    fprintf(fp,"tempreture: %u\n", ec->drive_motor[i].tempreture);
                    fprintf(fp,"input_voltage: %u\n", ec->drive_motor[i].input_voltage);
                    fprintf(fp,"main_current: %u\n", ec->drive_motor[i].main_current);
                    fprintf(fp,"--------------------\n");
                }
            }

            if(ec->have_fuel_battery){
                fprintf(fp,"have_fuel_battery: %u\n", ec->have_fuel_battery);
                fprintf(fp,"fuel_battery_voltage: %u\n", ec->fuel_battery_voltage);
                fprintf(fp,"fuel_battery_current: %u\n", ec->fuel_battery_current);
                fprintf(fp,"fuel_battery_consume_rate: %u\n", ec->fuel_battery_consume_rate);
                fprintf(fp,"fuel_battery_sum_probe: %u\n", ec->fuel_battery_sum_probe);
                fprintf(fp,"fuel_battery_probe:\n");
                for(int i = 0; i < ec->fuel_battery_sum_probe; i++){
                    fprintf(fp,"fuel_battery_probe: %u\t", ec->fuel_battery_probe[i]);
                }
                fprintf(fp,"\n");
                fprintf(fp,"fuel_battery_max_tem: %u\n", ec->fuel_battery_max_tem);
                fprintf(fp,"fuel_battery_max_tem_index: %u\n", ec->fuel_battery_max_tem_index);
                fprintf(fp,"fuel_battery_max_con: %u\n", ec->fuel_battery_max_con);
                fprintf(fp,"fuel_battery_max_con_index: %u\n", ec->fuel_battery_max_con_index);
                fprintf(fp,"fuel_battery_max_pre: %u\n", ec->fuel_battery_max_pre);
                fprintf(fp,"fuel_battery_max_pre_index: %u\n", ec->fuel_battery_max_pre_index);
                fprintf(fp,"fuel_battery_dc_status: %u\n", ec->fuel_battery_dc_status);
            }

            if(ec->have_engine){
                fprintf(fp,"engine_status: %u\n", ec->engine_status);
                fprintf(fp,"engine_speed: %u\n", ec->engine_speed);
                fprintf(fp,"engine_fuel_consume_rate: %u\n", ec->engine_fuel_consume_rate);
            }

            if(ec->have_pos){
                fprintf(fp,"pos_status: %u\n", ec->pos_status);
                fprintf(fp,"pos_longitude: %u\n", ec->pos_longitude);
                fprintf(fp,"pos_latitude: %u\n", ec->pos_latitude);
            }

            if(ec->have_maxi){
                fprintf(fp,"max_vol_bat_sys_index: %u\n", ec->max_vol_bat_sys_index);
                fprintf(fp,"max_vol_bat_ini_index: %u\n", ec->max_vol_bat_ini_index);
                fprintf(fp,"bat_ini_max_vol: %u\n", ec->bat_ini_max_vol);
                fprintf(fp,"min_vol_bat_sys_index: %u\n", ec->min_vol_bat_sys_index);
                fprintf(fp,"min_vol_bat_ini_index: %u\n", ec->min_vol_bat_ini_index);
                fprintf(fp,"bat_ini_min_vol: %u\n", ec->bat_ini_min_vol);
                fprintf(fp,"max_tem_sys_index: %u\n", ec->max_tem_sys_index);
                fprintf(fp,"max_tem_probe_index: %u\n", ec->max_tem_probe_index);
                fprintf(fp,"max_tem: %u\n", ec->max_tem);
                fprintf(fp,"min_tem_sys_index: %u\n", ec->min_tem_sys_index);
                fprintf(fp,"min_tem_probe_index: %u\n", ec->min_tem_probe_index);
                fprintf(fp,"min_tem: %u\n", ec->min_tem);
            }

            if(ec->have_warn){
                fprintf(fp,"warn_max_level: %u\n", ec->warn_max_level);
                fprintf(fp,"warn_general_mark: %u\n", ec->warn_general_mark);
                fprintf(fp,"warn_charge_app_number: %u\n", ec->warn_charge_app_number);
                for(int i = 0; i < ec->warn_charge_app_number; i++){
                    fprintf(fp,"\t%u", ec->warn_charge_app[i]);
                }
                fprintf(fp,"\n");

                fprintf(fp,"warn_drive_motor_number: %u\n", ec->warn_drive_motor_number);
                for(int i = 0; i < ec->warn_drive_motor_number; i++){
                    fprintf(fp,"\t%u", ec->warn_drive_motor_app[i]);
                }
                fprintf(fp,"\n");

                fprintf(fp,"warn_engine_number: %u\n", ec->warn_engine_number);
                for(int i = 0; i < ec->warn_engine_number; i++){
                    fprintf(fp,"\t%u", ec->warn_engine_app[i]);
                }
                fprintf(fp,"\n");

                fprintf(fp,"warn_other_number: %u\n", ec->warn_other_number);
                for(int i = 0; i < ec->warn_other_number; i++){
                    fprintf(fp,"\t%u", ec->warn_other_app[i]);
                }
                fprintf(fp,"\n");
            }
            break;
        }
        case CAR_LOGOUT:{
            fprintf(fp,"car_logout_seq: %u\n", ec->car_logout_seq);
            break;
        }
        case PLAT_LOGIN:{
            fprintf(fp,"plat_login_seq: %u\n", ec->plat_login_seq);
            fprintf(fp,"plat_login_username: %s\n", ec->plat_login_username);
            fprintf(fp,"plat_login_password: %s\n", ec->plat_login_password);
            fprintf(fp,"plat_login_encrypt_rule: %u\n", ec->plat_login_encrypt_rule);
            break;
        }
        case PLAT_LOGOUT:{
            fprintf(fp,"plat_logout_seq: %u\n", ec->plat_logout_seq);
            break;
        }
    }

    fprintf(fp,"==================================================\n");
    fclose(fp);
}

int main()
{
        unsigned char ArrayHex[1441] = {0};
        StringToBuff(packet, ArrayHex);
        /*if(ArrayHex[0] == 0x23 && ArrayHex[1] == 0x23){
            printf("WC Bin!\n");
        }

        */
        struct myobject* t = (struct myobject*)malloc(sizeof(struct myobject));
        t->ec = (struct ELECTRONIC_CAR*)malloc(sizeof(struct ELECTRONIC_CAR));
        t->ec->have_drive           =0;
        t->ec->have_engine          =0;
        t->ec->have_fuel_battery    =0;
        t->ec->have_maxi            =0;
        t->ec->have_pos             =0;
        t->ec->have_warn            =0;
        t->ec->have_whole_char      =0;
        t->ec->car_login_charge_system_code=NULL;
        t->ec->drive_motor= NULL;
        t->ec->fuel_battery_probe= NULL;
        t->ec->warn_charge_app= NULL;
        t->ec->warn_drive_motor_app= NULL;
        t->ec->warn_engine_app= NULL;
        t->ec->warn_other_app= NULL;




        if (t->ec == NULL)
        {
                return 0;
        }
        uint32_t tcp_payload_len = 0;
        uint8_t *tcp_payload = ArrayHex;
        if(!header_parse(t, tcp_payload)){
                printf("0x23 not match.\n");
                return 0;
        }
        //������ļ�¼���Ⱥ�ʵ�ʳ��ȶԲ��ϵĻ�����������
        if(24 + t->ec->data_len + 1 > tcp_payload_len){
                printf("mark data length > real length.\n");
                /*return 0;*/
        }
        //���û�����ݰ���Ļ�,ֱ�ӷ���
        if(t->ec->data_len == 0){
                return 1;
        }
        //��ʼ�������ݰ���Ľ���
        if(!body_parse(t->ec, t->ec->data_len, &tcp_payload[24])){
                printf("body error.\n");
                return 0;
        }
        Fout_put(t->ec);
        return 1;
}


/*
void out_put(struct ELECTRONIC_CAR* ec){
    printf("==================================================\n");
    printf("command_symbol: %u\n", ec->command_symbol);
    printf("respond_symbol: %u\n", ec->respond_symbol);
    printf("vin: %s\n", ec->vin);
    printf("encrypt_method: %u\n", ec->encrypt_method);
    printf("data_len: %u\n", ec->data_len);
    printf("general_time: %u��%u��%u��%uʱ%u��%u��\n", ec->general_time.year, ec->general_time.month ,  ec->general_time.day, ec->general_time.hour, ec->general_time.minute, ec->general_time.second);
    printf("--------------------------------------------------\n");
    switch(ec->command_symbol){
        case CAR_LOGIN:{
            printf("car_login_seq: %u\n", ec->car_login_seq);
            printf("car_login_iccid: %s\n", ec->car_login_iccid);
            printf("car_login_n: %u\n", ec->car_login_n);
            printf("car_login_m: %u\n", ec->car_login_m);
            printf("car_login_charge_system_code: %s\n", ec->car_login_charge_system_code);
            break;
        }
        case REAL_INFORMATION:{
            if(ec->have_whole_char){
                printf("whole_car_car_status: %u\n", ec->whole_car_car_status);
                printf("whole_car_charge_status: %u\n", ec->whole_car_charge_status);
                printf("whole_car_run_status: %u\n", ec->whole_car_run_status);
                printf("whole_car_speed: %u\n", ec->whole_car_speed);
                printf("whole_car_distance: %u\n", ec->whole_car_distance);
                printf("whole_car_voltage: %u\n", ec->whole_car_voltage);
                printf("whole_car_current: %u\n", ec->whole_car_current);
                printf("whole_car_soc: %u\n", ec->whole_car_soc);
                printf("whole_car_dc_status: %u\n", ec->whole_car_dc_status);
                printf("whole_car_gear: %u\n", ec->whole_car_gear);
                printf("whole_car_resistance: %u\n", ec->whole_car_resistance);
                printf("whole_car_preset: %u\n", ec->whole_car_preset);
                printf("--------------------------------------------------\n");
            }

            if(ec->have_drive){
                printf("drive_quantity: %u\n", ec->drive_quantity);
                for(int i = 0; i < ec->drive_quantity; i++){
                    printf("--------------------\n");
                    printf("number: %u\n", ec->drive_motor[i].number);
                    printf("status: %u\n", ec->drive_motor[i].status);
                    printf("control_tempreture: %u\n", ec->drive_motor[i].control_tempreture);
                    printf("speed: %u\n", ec->drive_motor[i].speed);
                    printf("torsion: %u\n", ec->drive_motor[i].torsion);
                    printf("tempreture: %u\n", ec->drive_motor[i].tempreture);
                    printf("input_voltage: %u\n", ec->drive_motor[i].input_voltage);
                    printf("main_current: %u\n", ec->drive_motor[i].main_current);
                    printf("--------------------\n");
                }
                printf("--------------------------------------------------\n");
            }

            if(ec->have_fuel_battery){
                printf("have_fuel_battery: %u\n", ec->have_fuel_battery);
                printf("fuel_battery_voltage: %u\n", ec->fuel_battery_voltage);
                printf("fuel_battery_current: %u\n", ec->fuel_battery_current);
                printf("fuel_battery_consume_rate: %u\n", ec->fuel_battery_consume_rate);
                printf("fuel_battery_sum_probe: %u\n", ec->fuel_battery_sum_probe);
                printf("fuel_battery_probe:\n");
                for(int i = 0; i < ec->fuel_battery_sum_probe; i++){
                    printf("fuel_battery_probe: %u\t", ec->fuel_battery_probe[i]);
                }
                printf("\n");
                printf("fuel_battery_max_tem: %u\n", ec->fuel_battery_max_tem);
                printf("fuel_battery_max_tem_index: %u\n", ec->fuel_battery_max_tem_index);
                printf("fuel_battery_max_con: %u\n", ec->fuel_battery_max_con);
                printf("fuel_battery_max_con_index: %u\n", ec->fuel_battery_max_con_index);
                printf("fuel_battery_max_pre: %u\n", ec->fuel_battery_max_pre);
                printf("fuel_battery_max_pre_index: %u\n", ec->fuel_battery_max_pre_index);
                printf("fuel_battery_dc_status: %u\n", ec->fuel_battery_dc_status);
                printf("--------------------------------------------------\n");
            }

            if(ec->have_engine){
                printf("engine_status: %u\n", ec->engine_status);
                printf("engine_speed: %u\n", ec->engine_speed);
                printf("engine_fuel_consume_rate: %u\n", ec->engine_fuel_consume_rate);
                printf("\n");
            }

            if(ec->have_pos){
                printf("pos_status: %u\n", ec->pos_status);
                printf("pos_longitude: %u\n", ec->pos_longitude);
                printf("pos_latitude: %u\n", ec->pos_latitude);
                printf("\n");
            }

            if(ec->have_maxi){
                printf("max_vol_bat_sys_index: %u\n", ec->max_vol_bat_sys_index);
                printf("max_vol_bat_ini_index: %u\n", ec->max_vol_bat_ini_index);
                printf("bat_ini_max_vol: %u\n", ec->bat_ini_max_vol);
                printf("min_vol_bat_sys_index: %u\n", ec->min_vol_bat_sys_index);
                printf("min_vol_bat_ini_index: %u\n", ec->min_vol_bat_ini_index);
                printf("bat_ini_min_vol: %u\n", ec->bat_ini_min_vol);
                printf("max_tem_sys_index: %u\n", ec->max_tem_sys_index);
                printf("max_tem_probe_index: %u\n", ec->max_tem_probe_index);
                printf("max_tem: %u\n", ec->max_tem);
                printf("min_tem_sys_index: %u\n", ec->min_tem_sys_index);
                printf("min_tem_probe_index: %u\n", ec->min_tem_probe_index);
                printf("min_tem: %u\n", ec->min_tem);
                printf("\n");
            }

            if(ec->have_warn){
                printf("warn_max_level: %u\n", ec->warn_max_level);
                printf("warn_general_mark: %u\n", ec->warn_general_mark);
                printf("warn_charge_app_number: %u\n", ec->warn_charge_app_number);
                for(int i = 0; i < ec->warn_charge_app_number; i++){
                    printf("\t%u", ec->warn_charge_app[i]);
                }
                printf("\n");

                printf("warn_drive_motor_number: %u\n", ec->warn_drive_motor_number);
                for(int i = 0; i < ec->warn_drive_motor_number; i++){
                    printf("\t%u", ec->warn_drive_motor_app[i]);
                }
                printf("\n");

                printf("warn_engine_number: %u\n", ec->warn_engine_number);
                for(int i = 0; i < ec->warn_engine_number; i++){
                    printf("\t%u", ec->warn_engine_app[i]);
                }
                printf("\n");

                printf("warn_other_number: %u\n", ec->warn_other_number);
                for(int i = 0; i < ec->warn_other_number; i++){
                    printf("\t%u", ec->warn_other_app[i]);
                }
                printf("--------------------------------------------------\n");
            }
            break;
        }
        case SUPP_INFORMATION:{
            if(ec->have_whole_char){
                printf("whole_car_car_status: %u\n", ec->whole_car_car_status);
                printf("whole_car_charge_status: %u\n", ec->whole_car_charge_status);
                printf("whole_car_run_status: %u\n", ec->whole_car_run_status);
                printf("whole_car_speed: %u\n", ec->whole_car_speed);
                printf("whole_car_distance: %u\n", ec->whole_car_distance);
                printf("whole_car_voltage: %u\n", ec->whole_car_voltage);
                printf("whole_car_current: %u\n", ec->whole_car_current);
                printf("whole_car_soc: %u\n", ec->whole_car_soc);
                printf("whole_car_dc_status: %u\n", ec->whole_car_dc_status);
                printf("whole_car_gear: %u\n", ec->whole_car_gear);
                printf("whole_car_resistance: %u\n", ec->whole_car_resistance);
                printf("whole_car_preset: %u\n", ec->whole_car_preset);
                printf("--------------------------------------------------\n");
            }

            if(ec->have_drive){
                printf("drive_quantity: %u\n", ec->drive_quantity);
                for(int i = 0; i < ec->drive_quantity; i++){
                    printf("--------------------\n");
                    printf("number: %u\n", ec->drive_motor[i].number);
                    printf("status: %u\n", ec->drive_motor[i].status);
                    printf("control_tempreture: %u\n", ec->drive_motor[i].control_tempreture);
                    printf("speed: %u\n", ec->drive_motor[i].speed);
                    printf("torsion: %u\n", ec->drive_motor[i].torsion);
                    printf("tempreture: %u\n", ec->drive_motor[i].tempreture);
                    printf("input_voltage: %u\n", ec->drive_motor[i].input_voltage);
                    printf("main_current: %u\n", ec->drive_motor[i].main_current);
                    printf("--------------------\n");
                }
                printf("--------------------------------------------------\n");
            }

            if(ec->have_fuel_battery){
                printf("have_fuel_battery: %u\n", ec->have_fuel_battery);
                printf("fuel_battery_voltage: %u\n", ec->fuel_battery_voltage);
                printf("fuel_battery_current: %u\n", ec->fuel_battery_current);
                printf("fuel_battery_consume_rate: %u\n", ec->fuel_battery_consume_rate);
                printf("fuel_battery_sum_probe: %u\n", ec->fuel_battery_sum_probe);
                printf("fuel_battery_probe:\n");
                for(int i = 0; i < ec->fuel_battery_sum_probe; i++){
                    printf("fuel_battery_probe: %u\t", ec->fuel_battery_probe[i]);
                }
                printf("\n");
                printf("fuel_battery_max_tem: %u\n", ec->fuel_battery_max_tem);
                printf("fuel_battery_max_tem_index: %u\n", ec->fuel_battery_max_tem_index);
                printf("fuel_battery_max_con: %u\n", ec->fuel_battery_max_con);
                printf("fuel_battery_max_con_index: %u\n", ec->fuel_battery_max_con_index);
                printf("fuel_battery_max_pre: %u\n", ec->fuel_battery_max_pre);
                printf("fuel_battery_max_pre_index: %u\n", ec->fuel_battery_max_pre_index);
                printf("fuel_battery_dc_status: %u\n", ec->fuel_battery_dc_status);
                printf("--------------------------------------------------\n");
            }

            if(ec->have_engine){
                printf("engine_status: %u\n", ec->engine_status);
                printf("engine_speed: %u\n", ec->engine_speed);
                printf("engine_fuel_consume_rate: %u\n", ec->engine_fuel_consume_rate);
                printf("--------------------------------------------------\n");
            }

            if(ec->have_pos){
                printf("pos_status: %u\n", ec->pos_status);
                printf("pos_longitude: %u\n", ec->pos_longitude);
                printf("pos_latitude: %u\n", ec->pos_latitude);
                printf("--------------------------------------------------\n");
            }

            if(ec->have_maxi){
                printf("max_vol_bat_sys_index: %u\n", ec->max_vol_bat_sys_index);
                printf("max_vol_bat_ini_index: %u\n", ec->max_vol_bat_ini_index);
                printf("bat_ini_max_vol: %u\n", ec->bat_ini_max_vol);
                printf("min_vol_bat_sys_index: %u\n", ec->min_vol_bat_sys_index);
                printf("min_vol_bat_ini_index: %u\n", ec->min_vol_bat_ini_index);
                printf("bat_ini_min_vol: %u\n", ec->bat_ini_min_vol);
                printf("max_tem_sys_index: %u\n", ec->max_tem_sys_index);
                printf("max_tem_probe_index: %u\n", ec->max_tem_probe_index);
                printf("max_tem: %u\n", ec->max_tem);
                printf("min_tem_sys_index: %u\n", ec->min_tem_sys_index);
                printf("min_tem_probe_index: %u\n", ec->min_tem_probe_index);
                printf("min_tem: %u\n", ec->min_tem);
                printf("--------------------------------------------------\n");
            }

            if(ec->have_warn){
                printf("warn_max_level: %u\n", ec->warn_max_level);
                printf("warn_general_mark: %u\n", ec->warn_general_mark);
                printf("warn_charge_app_number: %u\n", ec->warn_charge_app_number);
                for(int i = 0; i < ec->warn_charge_app_number; i++){
                    printf("\t%u", ec->warn_charge_app[i]);
                }
                printf("\n");

                printf("warn_drive_motor_number: %u\n", ec->warn_drive_motor_number);
                for(int i = 0; i < ec->warn_drive_motor_number; i++){
                    printf("\t%u", ec->warn_drive_motor_app[i]);
                }
                printf("\n");

                printf("warn_engine_number: %u\n", ec->warn_engine_number);
                for(int i = 0; i < ec->warn_engine_number; i++){
                    printf("\t%u", ec->warn_engine_app[i]);
                }
                printf("\n");

                printf("warn_other_number: %u\n", ec->warn_other_number);
                for(int i = 0; i < ec->warn_other_number; i++){
                    printf("\t%u", ec->warn_other_app[i]);
                }
                printf("--------------------------------------------------\n");
            }
            break;
        }
        case CAR_LOGOUT:{
            printf("car_logout_seq: %u\n", ec->car_logout_seq);
            break;
        }
        case PLAT_LOGIN:{
            printf("plat_login_seq: %u\n", ec->plat_login_seq);
            printf("plat_login_username: %s\n", ec->plat_login_username);
            printf("plat_login_password: %s\n", ec->plat_login_password);
            printf("plat_login_encrypt_rule: %u\n", ec->plat_login_encrypt_rule);
            break;
        }
        case PLAT_LOGOUT:{
            printf("plat_logout_seq: %u\n", ec->plat_logout_seq);
            break;
        }
    }

    printf("==================================================\n");
}
*/
