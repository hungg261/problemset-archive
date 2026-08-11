<#assign SMALL = 10000000>
<#assign BIG = 1000000000000000000>

<#-- Subtask 1 -->
<#list 1..1 as i>
gen ${i} --min_val=${SMALL / 2} --max_val=${SMALL} --is_g=0 > $
</#list>

<#list 1..9 as i>
gen ${i} --min_val=${SMALL / 2} --max_val=${SMALL} --is_g=1 > $
</#list>

<#-- Subtask 2 -->
<#list 1..1 as i>
gen ${i} --min_val=${BIG / 2} --max_val=${BIG} --is_g=0 > $
</#list>

<#list 1..9 as i>
gen ${i} --min_val=${BIG / 2} --max_val=${BIG} --is_g=1 > $
</#list>
