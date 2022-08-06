set ns [new Simulator]
set namfile [open ex_01.nam w]
$ns namtrace-all $namfile

set tracefile [open ex_01.tr w]  
$ns trace-all $tracefile

set n0 [$ns node] 
set n1 [$ns node] 
set n2 [$ns node] 
set n3 [$ns node] 
set n4 [$ns node]

$ns duplex-link $n0 $n4 1Mb 10ms DropTail 
$ns duplex-link $n1 $n4 1Mb 10ms DropTail 
$ns duplex-link $n4 $n3 1Mb 10ms DropTail 
$ns duplex-link $n4 $n2 1Mb 10ms DropTail

set tcp [new Agent/TCP] 
$ns attach-agent $n0 $tcp 

set sink [new Agent/TCPSink] 
$ns attach-agent $n3 $sink  

$ns connect $tcp $sink

set ftp [new Application/FTP] 
$ftp attach-agent $tcp

set udp [new Agent/UDP] 
$ns attach-agent $n1 $udp

set null [new Agent/Null] 
$ns attach-agent $n2 $null

$ns connect $udp $null

$udp set class_ 1 
$ns color 1 Blue

$tcp set class_ 2 
$ns color 2 Red

set cbr [new Application/Traffic/CBR] 
$cbr set packetsize_ 500 
$cbr set interval_ 0.005 
$cbr attach-agent $udp

$ns at 0.0 "$cbr start" 
$ns at 0.0 "$ftp start" 
$ns at 9.0 "$cbr stop" 
$ns at 9.0 "$ftp stop"

proc finish {} {              
global ns namfile tracefile          
$ns flush-trace        
close $namfile        
close $tracefile        
exec nam ex_01.nam &        
exit 0 
}

$ns at 10.0 "finish" 
$ns run