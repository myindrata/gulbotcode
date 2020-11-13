def mapping_cam2real(fpos_x, fpos_y):
    tinggi_real = 560
    panjang_real = 500
    lebar_real=300
    res_panjang=1280 #resolusi panjang frame
    res_lebar=960 #resolusi lebar frame
    robot_ydis=200 #jarak center robot terhadap sumbu x
    robot_xdis=(panjang_real/2) #jarak center robot terhadap sumbu y
    rasio_panjang=tinggi_real/panjang_real #rasio tinggi/panjang
    rasio_lebar=tinggi_real/lebar_real#rasio tinggi/lebar

    rasio_pcam2real=res_panjang/panjang_real
    rasio_lcam2real=res_lebar/lebar_real

    rpos_x=(fpos_x/rasio_pcam2real)
    rpos_y=lebar_real-(fpos_y/rasio_lcam2real)
    robot2rpos_x=rpos_x-robot_xdis
    robot2rpos_y=robot_ydis+lebar_real-rpos_y
    return robot2rpos_x,robot2rpos_y

print(mapping_cam2real(915,334))