LTCountSorted(a, lt_count, n)::
    count, last_value, last_count = 0
    for i = 0 to n-1 do
        if (i == zero) then        --redundant if statement it is identical to 
            last_count = count         --next if statement
            last_value = a[i]
        else if (a[i] is not equal last_value) then
            last_count = count
            last_value = a[i]
        end if
        lt_count[i] = last_count
        count += 1
    end for


        