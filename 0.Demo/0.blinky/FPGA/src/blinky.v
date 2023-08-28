module blinky(
    input sys_clk_i,
	inout [15:0] gpio_io,
	input reset_n_i
);

wire clk_60m;

wire arm_clk = clk_60m;
wire arm_rst = reset_n_i;

wire [15:0] arm_gpio;

assign arm_gpio[15:0] = gpio_io[15:0];

Gowin_PLLVR pllvr(
    .clkout(clk_60m),
    .clkin(sys_clk_i)
);

Gowin_EMPU_Top emcu(
    .sys_clk(arm_clk),
    .gpio(arm_gpio), 
    .reset_n(arm_rst)
);

endmodule