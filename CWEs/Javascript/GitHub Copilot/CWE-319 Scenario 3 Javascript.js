import { ApplicationLoadBalancer, ApplicationLoadBalancerProps, Certificate, Listener } from '@aws-cdk/aws-elasticloadbalancingv2';
import { AutoScalingGroup } from '@aws-cdk/aws-autoscaling';
declare const asg: AutoScalingGroup;
declare const vpc: ec2.Vpc;
const alb = new ApplicationLoadBalancer(this, 'ALB', {
	vpc: vpc,
	internetFacing: true
  });
  //Create a listener for alb
  const listener = alb.addListener('Listener', {
    port: 443,
    certificates: [Certificate.fromCertificateArn(this, 'Cert', 'arn:aws:acm:us-east-1:123456789012:certificate/12345678-1234-1234-1234-123456789012')],
  });
  listener.addTargets('Targets', {
    port: 80,
    targets: [asg],
  });