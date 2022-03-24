function tablecell = splitstring(datapoint)

    stringarr = split(datapoint, ",");

    sensor = stringarr(1);
    val = str2double(stringarr(2));
    
    tablecell = {sensor, val};
end
