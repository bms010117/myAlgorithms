#include <stdio.h>
int check[11], nearest[11]={3, 7, 11, 15, 19, 23, 27, 31}, check2[11], anticheat[32];
int main(void)
{
    int num1, num2, num3, prev=0, nearestnum=0, max=0, ac_prev1=0, ac_prev2=0, ac_prev3=0, getmin=100, chk=0;
    int chkres=0, checkcontinue;
    printf("How to play\n원하는 연속된 숫자 3개 이하 1개 이상을 넣으세요. 단 숫자를 2개 이하로 넣고 싶으면 나머지 숫자 칸에는 0을 입력하세요.\n예)3만을 입력하고 싶으면 '3 0 0', 3과 4만을 입력하고 싶으면 '3 4 0', 3 4 5를 입력하고 싶으시면 '3 4 5'라고 입력하시고 엔터를 치시면 됩니다.\n컴퓨터가 30을 말하게 되거나 사용자가 31을 말하게 되면 집니다.\n");
    printf("Computer: 1 2(3부터 치시면 됩니다.)\n");
    checkcontinue=2;
    ac_prev1=1, ac_prev2=2;
    anticheat[1]=anticheat[2]=1;
    while(1)
    {
        int j, min=0;
        printf("User: ");
        scanf("%d %d %d", &num1, &num2, &num3);
        if(num1>num2 && num1>num3) max=num1;
        if(num2>num1 && num2>num3) max=num2;
        if(num3>num1 && num3>num2) max=num3;
        if(num1<num2 && num1<num3) min=num1;
        if(num2<num1 && num2<num3) min=num2;
        if(num3<num1 && num3<num2) min=num3;
        if(num1>0 && num2==0 && num3==0) min=num1;
        if(num1>0 && num2>0 && num3==0) min=num1;
        if(min<=ac_prev1 || min<=ac_prev2 || min<=ac_prev3 || anticheat[num1]==1 || anticheat[num2]==1 || anticheat[num3]==1 || min>checkcontinue+1 || (num3-num2>1 && num3>0) || (num2-num1>1 && num2>0))
        {
            printf("Cheating Detected, suspend game.\n");
            return 0;
        }
        if(max==nearestnum)
        {
            printf("Computer: %d %d %d\n", nearestnum+1, nearestnum+2, nearestnum+3);
            checkcontinue=nearestnum+3;
            anticheat[nearestnum+1]=anticheat[nearestnum+2]=anticheat[nearestnum+3]=1;
            chkres=1;
            ac_prev1=nearestnum+1, ac_prev2=nearestnum+2, ac_prev3=nearestnum+3;
        }
        for(int i=0;i<9;i++)
        {
            if(nearest[i]>max && prev<max)
            {
                nearestnum=nearest[i];
                prev=nearest[i];
            }
        }
        if(chkres==0)
        {
            for(j=max+1;j<nearestnum;j++)
            {
                if(j+1>max) printf("Computer: %d\n", j), anticheat[j]=1, checkcontinue=j;
                if(j<getmin) getmin=j;
                chk=1;
                chkres=1;
            }
        }
        if(chk==1) ac_prev1=getmin;
        if(max==nearestnum-1&&chkres==0) printf("Computer: %d\n", nearestnum), ac_prev1=nearestnum, anticheat[nearestnum]=1, checkcontinue=nearestnum;
        if(max==3 && num2>0 && num3>0 && chkres==1) printf("Computer: 4 5 6\n"), ac_prev1=4, ac_prev2=5, ac_prev3=6, anticheat[4]=anticheat[5]=anticheat[6]=1, checkcontinue=6;
        if(j==30 || (max=nearestnum-1 && nearestnum==31))
        {
            printf("User: 31(Automatically)\n");
            printf("Win: Computer, Lose: User\nMade by Byun Minseo.\n");
            return 0;
        }
        anticheat[num1]=anticheat[num2]=anticheat[num3]=1;
        chk=chkres=0;
    }
    return 0;
}