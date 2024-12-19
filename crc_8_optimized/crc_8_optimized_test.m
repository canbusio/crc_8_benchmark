mdl = 'crc_8_optimized';

% 加载Simulink模型
open_system(mdl);

% 设置仿真时间（根据需要调整）
set_param(mdl, 'StopTime', '0.07');

% 配置输入信号等
t = (0:0.01:0.07)';
in1 = uint8([0x0F 0xAA 0x00 0x55 0x00 0x00 0x00 0x00])';
in2 = boolean([1 0 0 0 0 0 0 0])';
in3 = boolean([0 0 0 1 0 0 0 0])';
in4 = boolean([1 1 1 1 0 0 0 0])';
ds = Simulink.SimulationData.Dataset;
ds = setElement(ds,1,timeseries(in1,t));
ds = setElement(ds,2,timeseries(in2,t));
ds = setElement(ds,3,timeseries(in3,t));
ds = setElement(ds,4,timeseries(in4,t));

% 运行仿真
simin = Simulink.SimulationInput(mdl);
simin = setExternalInput(simin,ds);
out = sim(simin);

% 展示仿真结果
result = out.yout{1}.Values;
for i=1:length(result.Time)
    fprintf('%.2fs: 0x%02X\n', result.Time(i), result.Data(i));
end

% 关闭Simulink模型
close_system(mdl, 0);
clear;