#ifndef CAMERA_H
#define CAMERA_H

#include "ray.h"
#include "rtweekend.h"

__device__ vec3 random_in_unit_disk(curandState* local_rand_state)
{
  vec3 p;
  do
  {
    p = 2.0f * vec3(curand_uniform(local_rand_state), curand_uniform(local_rand_state), 0) - vec3(1, 1, 0);
  } while (dot(p, p) >= 1.0f);
  return p;
}

class camera
{
public:
  __device__ camera(
      vec3 lookfrom,
      vec3 lookat,
      vec3 vup,
      double vfov,  // vertical field-of-view in degrees
      double aspect_ratio,
      double aperture,
      double focus_dist)
  {
    auto theta = vfov * ((float)M_PI) / 180.0f;
    auto h = tan(theta / 2);
    auto viewport_height = 2.0 * h;
    auto viewport_width = aspect_ratio * viewport_height;

    w = unit_vector(lookfrom - lookat);
    u = unit_vector(cross(vup, w));
    v = cross(w, u);

    origin = lookfrom;
    horizontal = focus_dist * viewport_width * u;
    vertical = focus_dist * viewport_height * v;
    lower_left_corner = origin - horizontal / 2 - vertical / 2 - focus_dist * w;

    lens_radius = aperture / 2;
  }

  __device__ ray get_ray(float s, float t, curandState* local_rand_state)
  {
    vec3 rd = lens_radius * random_in_unit_disk(local_rand_state);
    vec3 offset = u * rd.x() + v * rd.y();
    return ray(origin + offset, lower_left_corner + s * horizontal + t * vertical - origin - offset);
  }

private:
  vec3 origin;
  vec3 lower_left_corner;
  vec3 horizontal;
  vec3 vertical;
  vec3 u, v, w;
  double lens_radius;
};

#endif
