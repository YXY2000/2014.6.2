#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()//��������Χ��Լ��
{
    float denominator=0;//��ĸ
    float numerator=0;//����
    int son=0;//��������
    int mother=0;//������ĸ
    int res_son=0;//�������
    int res_mot=0;//�����ĸ
    int sign=0;//�жϽ��������
    int times=0;//����_Լ��
    //int ts_int=1;//����_��С����Ϊ����
    int ch=0;
    while(1)
    {
        printf("\n                   ��������Χ��Լ�ֳ���(����������С������)\n");
        printf("\n�������:");
        scanf("%f",&numerator);
        printf("\n�����ĸ��");
        scanf("%f",&denominator);
        if(denominator==0)
        {
            printf("\n go_wrong \n");
        }
        else if(numerator==0)
        {
            printf("\n result=0 \n");
            res_son=0;
            res_mot=0;
        }
        else
        {
            if(denominator<0||numerator<0)//�жϷ��ӷ�ĸ�����ԣ���ʱsignΪ-1��
            {
                if(denominator<0&&numerator<0)//��Ϊ��
                {
                    sign=0;
                    denominator=-denominator;
                    numerator=-numerator;
                }
                else if(denominator>0&&numerator<0)//һ��һ��
                {
                    sign=-1;
                    numerator=-numerator;
                }
                else if(denominator<0&&numerator>0)//һ��һ��
                {
                    sign=-1;
                    denominator=-denominator;
                }
            }

                son=numerator;
                mother=denominator;
                if(mother!=denominator||son!=numerator)//�ж��Ƿ�ΪС��
                {
                    //ts_int=1;
                    while(1)//��ʮ��Ϊ����**���ӹ��ܣ�ts_intΪС�����λ����
                    {
                        numerator=numerator*10;
                        denominator=denominator*10;
                        son=numerator;
                        mother=denominator;
                        if(son==numerator&&mother==denominator)
                        {
                            //printf("%d",ts_int);
                            break;
                        }
                        //else ts_int++;
                    }
                    //printf("\n result=%d/%d \n",son,mother);
                }
                    if(mother==son)//���ӷ�ĸ���
                    {
                        if(sign==-1)printf("\n result= ** -1 \n");
                        else printf("\n result=1 \n");
                    }
                    else{
                        if(mother>son)//�����
                        {
                            printf("\n ����� \n");
                            if(mother%son==0&&sign==-1)printf("\n result= ** -1/%d \n",mother/son);//���ӷ�ĸ�ɱ���
                            else if(mother%son==0&&sign==0)printf("\n result=1/%d \n",mother/son);
                            else{
                                while(1)//���Ĳ���
                                {
                                    for(times=2;(son%times!=0||mother%times!=0)&&times<son;times++);
                                    if(times==son)break;
                                    else{
                                        mother=mother/times;
                                        son=son/times;
                                    }
                                }
                                if(sign==-1)printf("\n result= ** -%d/%d \n",son,mother);
                                else printf("\n result=%d/%d \n",son,mother);
                            }
                        }
                        else if(mother<son)//�ٷ���
                        {
                            printf("\n �ٷ��� \n");
                            if(son%mother==0&&sign==-1)printf("\n result= ** -%d \n",son/mother);//���ӷ�ĸ�ɱ���
                            else if(son%mother==0&&sign==0)printf("\n result=%d \n",son/mother);
                            else{
                                while(1)//���Ĳ���
                                {
                                    for(times=2;(son%times!=0||mother%times!=0)&&times<mother;times++);
                                    if(times==mother)break;
                                    else{
                                        mother=mother/times;
                                        son=son/times;
                                    }
                                }
                                if(sign==-1)printf("\n result= ** -%d/%d \n",son,mother);
                                else printf("\n result=%d/%d \n",son,mother);
                            }
                        }
                    }
            }
        printf("\n*********************************�����������**********************************\n");
        ch=getche();
        system("cls");//����
        sign=0;
    }
    return 0;
}
