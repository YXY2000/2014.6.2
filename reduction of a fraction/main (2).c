#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()//有理数范围内约分
{
    float denominator=0;//分母
    float numerator=0;//分子
    int son=0;//整数分子
    int mother=0;//整数分母
    int res_son=0;//结果分子
    int res_mot=0;//结果分母
    int sign=0;//判断结果正负性
    int times=0;//次数_约分
    //int ts_int=1;//次数_把小数归为整数
    int ch=0;
    while(1)
    {
        printf("\n                   有理数范围内约分程序(包括正负、小数、零)\n");
        printf("\n输入分子:");
        scanf("%f",&numerator);
        printf("\n输入分母：");
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
            if(denominator<0||numerator<0)//判断分子分母正负性，负时sign为-1；
            {
                if(denominator<0&&numerator<0)//都为负
                {
                    sign=0;
                    denominator=-denominator;
                    numerator=-numerator;
                }
                else if(denominator>0&&numerator<0)//一正一负
                {
                    sign=-1;
                    numerator=-numerator;
                }
                else if(denominator<0&&numerator>0)//一正一负
                {
                    sign=-1;
                    denominator=-denominator;
                }
            }

                son=numerator;
                mother=denominator;
                if(mother!=denominator||son!=numerator)//判断是否为小数
                {
                    //ts_int=1;
                    while(1)//乘十变为整数**附加功能：ts_int为小数点后位数；
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
                    if(mother==son)//分子分母相等
                    {
                        if(sign==-1)printf("\n result= ** -1 \n");
                        else printf("\n result=1 \n");
                    }
                    else{
                        if(mother>son)//真分数
                        {
                            printf("\n 真分数 \n");
                            if(mother%son==0&&sign==-1)printf("\n result= ** -1/%d \n",mother/son);//分子分母成倍数
                            else if(mother%son==0&&sign==0)printf("\n result=1/%d \n",mother/son);
                            else{
                                while(1)//核心部分
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
                        else if(mother<son)//假分数
                        {
                            printf("\n 假分数 \n");
                            if(son%mother==0&&sign==-1)printf("\n result= ** -%d \n",son/mother);//分子分母成倍数
                            else if(son%mother==0&&sign==0)printf("\n result=%d \n",son/mother);
                            else{
                                while(1)//核心部分
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
        printf("\n*********************************按任意键继续**********************************\n");
        ch=getche();
        system("cls");//清屏
        sign=0;
    }
    return 0;
}
