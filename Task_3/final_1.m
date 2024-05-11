delete(instrfind); 
s = serialport("COM8", 2000000);

figure;
numSignals = 6; 
hPlot = gobjects(numSignals, 1); 
buffer = NaN(numSignals, 50);

for i = 1:numSignals
   
    subplot(numSignals, 1, i);
    hPlot(i) = plot(NaN, NaN);
    ylabel(['Signal ', num2str(i)]);
    xlim([1, 21]);
    ylim([-0.5, 5.5]); 
end
xlabel('Time (Sample Index)'); 

updateRate = 0; 
counter = 0;
tic;
while  toc < 15
    if s.NumBytesAvailable > 0
        data = readline(s);
        values = str2double(split(data, ',')); 
        if length(values) == numSignals 
            newValues = reshape(values, [], 1);  r
            buffer = [buffer(:, 2:end), newValues]; 
            
            counter = counter + 1;
            if counter >= updateRate
                for k = 1:numSignals
                    set(hPlot(k), 'YData', buffer(k, :), 'XData', 1:50);
                end
                drawnow;
                counter = 0; 
            end
        end
    end
    pause(0.1); 
end

clear s;
