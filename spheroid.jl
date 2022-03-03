function spheroid(N,r,center,zstretch)
    pts = Matrix{Float64}(undef,3,N)
    phi = π*(3-sqrt(5)) # golden angle in radians
    for i = 1:N
        ytmp   = 1 - ((i-1)/(N-1))*2
        radius = sqrt(1-ytmp^2)
        theta    = phi*i
        pts[1,i] = cos(theta) * radius * r + center[1]
        pts[2,i] = ytmp * r + center[2]
        pts[3,i] = zstretch * sin(theta) * radius * r + center[3]
    end
    # Output
    return pts
end
