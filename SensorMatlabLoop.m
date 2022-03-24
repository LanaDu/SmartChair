hc05 = bluetooth("HC-05", 1); % Create bluetooth object
ButtonHandle = uicontrol('Style', 'PushButton', ...
                         'String', 'Stop loop', ...
                         'Callback', 'delete(gcbf)'); % Create button for quick loop stopping
data = cell2table(cell(0,2), 'VariableNames', {'Sensor', 'Value'}); % Initialise empty table

while true 
    datapoint = readline(hc05); % read sensor value
    datacell = splitstring(datapoint); % create cell to add to table
    if isempty(data)
        if strlength(datapoint) == 8 && contains(datapoint, "A1") % table must start at sensor A1
            data = [data; datacell];
        end
    else
        data = [data; datacell];
    end 
    % break out of loop 
    if ~ishandle(ButtonHandle)
        disp('Loop stopped');
        break;
    end  
end     
clear hc05





