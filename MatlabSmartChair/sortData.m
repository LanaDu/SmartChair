function [data, labels] = sortData(text,num,class)

m = length(num);
labels = [];
data = [];
i = 1;
y = 1;
initial = strcmp(text(1,1),'A1');

for n=1:m
    if initial == 0
        n = n+1;
        initial = strcmp(text(n,1),'A1');
    else
        nextrow = strcmp(text(n,1),'A13');
        if nextrow == 1
            data(y,13)= num(n);
            data(y,1:12)= datacollect(y,1:12);
            y = y+1;
            i = 1;
            labels = [labels; class];    
        else
            datacollect(y,i)= num(n);
            i = i+1;
        end

    end
    
end